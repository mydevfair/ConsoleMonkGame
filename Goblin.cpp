//
// Created by cfair on 29/03/2024.
//
#include "Goblin.h"
#include "Pch.h"
#include "PrintFunction.h"
#include "Monk.h"
#include "MainMenu.h"
#include "Action.h"

using namespace std;

Goblin::Goblin()
        : Player("", 10, 2) {
}

string Goblin::getGoblinName() const {
    return goblinName;
}

int Goblin::takeDamage(int damage) {
    return healthPoints = healthPoints - damage;
}

extern bool isActionSuccessful() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    return rand() % 2 == 0;
}

void Goblin::GoblinFight(Monk &myMonk) {
    const string monsterRoomTextPath = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/MonsterRoom.txt";
    const string deathTextPath = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/YouDied.txt";
    Goblin myGoblin = Goblin();
    int fightOrDefend;

    while (true) {
        system("cls");
        do {
            PrintFunction::printTxtFile(monsterRoomTextPath);
            cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
                 << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
            cout << endl << "| Monster: " << myGoblin.getGoblinName() << " | HealthPoints: "
                 << myGoblin.getHealthPoints()
                 << " | AttackPoints: " << myGoblin.getAttackPoints() << " |" << endl << endl;

            cout << "Do you want to fight (1) or defend (2)? ";
            cin >> fightOrDefend;
            if (fightOrDefend == 1) {
                if (Action::isSuccessful()) {
                    myGoblin.takeDamage(myMonk.getAttackPoints());
                    cout << "Monk attacks for " << myMonk.getAttackPoints() << " points!" << endl;
                    system("pause");
                    system("cls");
                    if (myGoblin.getHealthPoints() <= 0) {
                        PrintFunction::printTxtFile(monsterRoomTextPath);
                        cout << "Monk defeats the Ghost!" << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                } else {
                    cout << "Monk's attack missed!" << endl;
                    system("pause");
                    system("cls");
                }
            } else if (fightOrDefend == 2) {
                myMonk.modifyMonkHealth(min(myMonk.getHealthPoints() + 1, 15)); // Ensures HP doesn't exceed max
                cout << "Monk recovers 1 Health Point." << endl;
                system("pause");
                system("cls");
            } else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Invalid choice. Please enter 1 or 2." << endl << endl;
                system("pause");
                system("cls");
            } else if (fightOrDefend != 1 && fightOrDefend != 2) {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                system("pause");
                system("cls");
            }
        } while (fightOrDefend != 1 && fightOrDefend != 2 && !cin.fail());

        // Monster's turn
        PrintFunction::printTxtFile(monsterRoomTextPath);
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "| Monster: " << myGoblin.getGoblinName() << " | HealthPoints: " << myGoblin.getHealthPoints()
             << " | AttackPoints: " << myGoblin.getAttackPoints() << " |" << std::endl << endl;
        if (Action::isSuccessful()) {
            myMonk.modifyMonkHealth(myMonk.getHealthPoints() - myGoblin.getAttackPoints());
            cout << "Goblin attacks for " << myGoblin.getAttackPoints() << " points!" << endl;
            system("pause");
            system("cls");
            if (myMonk.getHealthPoints() <= 0) {
                PrintFunction::printTxtFile(monsterRoomTextPath);
                cout << "The Goblin defeats the Monk!" << endl;
                system("pause");
                string deathTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\YouDied.txt)";
                system("pause");
                system("cls");
                myMonk.restoreMonkHealthPoints();
                MainMenu::MainMenuChoice();
            }
        } else {
            cout << "Goblin's attack missed!" << endl;
            system("pause");
            system("cls");
        }
    }
}