//
// Created by cfair on 29/03/2024.
//

#include "Ghost.h"
#include "PrintFunction.h"
#include "MainMenu.h"
#include "Goblin.h"

using namespace std;

Ghost::Ghost()
    : Player("", 13, 3) {
}

string Ghost::getGhostName() const {
    return ghostName;
}

int Ghost::takeDamage(int damage) {
    return healthPoints = healthPoints - damage;
}

bool isActionSuccessful1() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    return rand() % 2 == 0;
}

void Ghost::GhostFight(Monk &myMonk) {
    string monsterRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\MonsterRoom.txt)";
    Ghost myGhost = Ghost();
    int fightOrDefend;
    while (true) {
        system("cls");
        PrintFunction::printTxtFile(monsterRoomTextImage);
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "| Ghost: " << myGhost.getGhostName() << " | HealthPoints: " << myGhost.getHealthPoints()
             << " | AttackPoints: " << myGhost.getAttackPoints() << " |" << endl << endl;

        cout << "Do you want to fight (1) or defend (2)? ";
        cin >> fightOrDefend;

        if (fightOrDefend == 1) {
            if (isActionSuccessful1()) {
                myGhost.takeDamage(myMonk.getAttackPoints());
                cout << "Monk attacks for " << myMonk.getAttackPoints() << " points!" << endl;
                system("pause");
                system("cls");
                if (myGhost.getHealthPoints() <= 0) {
                    PrintFunction::printTxtFile(monsterRoomTextImage);
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
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            system("pause");
            system("cls");
        }

        // Monster's turn
        PrintFunction::printTxtFile(monsterRoomTextImage);
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "| Ghost: " << myGhost.getGhostName() << " | HealthPoints: " << myGhost.getHealthPoints()
             << " | AttackPoints: " << myGhost.getAttackPoints() << " |" << endl << endl;
        if (isActionSuccessful1()) {
            myMonk.modifyMonkHealth(myMonk.getHealthPoints() - myGhost.getAttackPoints());
            cout << "Ghost attacks for " << myGhost.getAttackPoints() << " points!" << endl;
            system("pause");
            system("cls");
            if (myMonk.getHealthPoints() <= 0) {
                PrintFunction::printTxtFile(monsterRoomTextImage);
                cout << "The Ghost defeats the Monk!" << endl;
                system("pause");
                string deathTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\YouDied.txt)";
                system("pause");
                system("cls");
                myMonk.restoreMonkHealthPoints();
                MainMenu::MainMenuChoice();
            }
        } else {
            cout << "Ghost's attack missed!" << endl;
            system("pause");
            system("cls");
        }
    }
}


