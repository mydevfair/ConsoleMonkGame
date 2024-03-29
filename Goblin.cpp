//
// Created by cfair on 29/03/2024.
//

#include "Goblin.h"
#include "Pch.h"
#include "PrintFunction.h"
#include "Monk.h"
#include "MainMenu.h"

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

bool isActionSuccessful() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    return rand() % 2 == 0;
}

void Goblin::GoblinFight(Monk &myMonk) {
    string monsterRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\MonsterRoom.txt)";
    Goblin myGoblin = Goblin();
    int fightOrDefend;
    while (true) {
        system("cls");
        PrintFunction::printTxtFile(monsterRoomTextImage);

        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "| Goblin: " << myGoblin.getGoblinName() << " | HealthPoints: " << myGoblin.getHealthPoints()
             << " | AttackPoints: " << myGoblin.getAttackPoints() << " |" << endl << endl;

        cout << "Do you want to fight (1) or defend (2)? ";
        cin >> fightOrDefend;

        if (fightOrDefend == 1) {
            if (isActionSuccessful()) {
                myGoblin.takeDamage(myMonk.getAttackPoints());
                cout << "Monk attacks for " << myMonk.getAttackPoints() << " points!" << endl;
                system("pause");
                system("cls");
                if (myGoblin.getHealthPoints() <= 0) {
                    cout << "Monk defeats the goblin!" << endl;
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
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            system("pause");
            system("cls");
        }

        // Monster's turn
        PrintFunction::printTxtFile(monsterRoomTextImage);
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "| Goblin: " << myGoblin.getGoblinName() << " | HealthPoints: " << myGoblin.getHealthPoints()
             << " | AttackPoints: " << myGoblin.getAttackPoints() << " |" << endl << endl;
        if (isActionSuccessful()) {
            myMonk.modifyMonkHealth(myMonk.getHealthPoints() - myGoblin.getAttackPoints());
            cout << "Goblin attacks for " << myGoblin.getAttackPoints() << " points!" << endl;
            system("pause");
            system("cls");
            if (myMonk.getHealthPoints() <= 0) {
                cout << "The goblin defeats the Monk!" << endl;
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