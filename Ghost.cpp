//
// Created by cfair on 29/03/2024.
//
#include "Ghost.h"
#include "PrintFunction.h"
#include "MainMenu.h"
#include "Action.h"

using namespace std;

// Ghost constructor
Ghost::Ghost()
        : Player("", 13, 3) {
}

// Ghost Getters
string Ghost::getGhostName() const {
    return ghostName;
}

// Ghost Setters
int Ghost::takeDamage(int damage) {
    return healthPoints = healthPoints - damage;
}

// GhostFight function
void Ghost::GhostFight(Monk &myMonk) {
    const string monsterRoomTextImage = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/MonsterRoom.txt";
    const string deathTextImage = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/YouDied.txt";
    Ghost myGhost = Ghost();
    int fightOrDefend;
    bool isFightOver = false;
    // Fight loop
    while (!isFightOver) {
        system("cls");
        do {
            PrintFunction::printTxtFile(monsterRoomTextImage);
            cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
                 << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
            cout << endl << "| Monster: " << myGhost.getGhostName() << " | HealthPoints: " << myGhost.getHealthPoints()
                 << " | AttackPoints: " << myGhost.getAttackPoints() << " |" << endl << endl;

            cout << "Do you want to fight (1) or defend (2)? ";
            cin >> fightOrDefend;
            if (fightOrDefend == 1) {
                if (Action::isSuccessful()) {
                    myGhost.takeDamage(myMonk.getAttackPoints());
                    cout << "Monk attacks for " << myMonk.getAttackPoints() << " points!" << endl;
                    system("pause");
                    system("cls");
                    if (myGhost.getHealthPoints() <= 0) {
                        PrintFunction::printTxtFile(monsterRoomTextImage);
                        cout << endl << "Monk defeats the Ghost!" << endl << endl;
                        system("pause");
                        system("cls");
                        isFightOver = true;
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
        if (!isFightOver) {
            PrintFunction::printTxtFile(monsterRoomTextImage);
            cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
                 << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
            cout << endl << "| Monster: " << myGhost.getGhostName() << " | HealthPoints: " << myGhost.getHealthPoints()
                 << " | AttackPoints: " << myGhost.getAttackPoints() << " |" << std::endl << endl;
            if (Action::isSuccessful()) {
                myMonk.modifyMonkHealth(myMonk.getHealthPoints() - myGhost.getAttackPoints());
                cout << "Ghost attacks for " << myGhost.getAttackPoints() << " points!" << endl;
                system("pause");
                system("cls");
                if (myMonk.getHealthPoints() <= 0) {
                    PrintFunction::printTxtFile(monsterRoomTextImage);
                    cout << "The Ghost defeats the Monk!" << endl << endl;
                    system("pause");
                    system("cls");
                    PrintFunction::printTxtFile(deathTextImage);
                    system("pause");
                    system("cls");
                    // Restores Monk's health points and returns to main menu
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
}