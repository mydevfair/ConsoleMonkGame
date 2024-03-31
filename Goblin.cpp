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

// Constructor for the Goblin class
Goblin::Goblin()
        : Player("", 10, 2) {
}

// Getter for the Goblin's name
string Goblin::getGoblinName() const {
    return goblinName;
}

// Setter for the Goblin's Health Points
int Goblin::takeDamage(int damage) {
    return healthPoints = healthPoints - damage;
}

// Function to initiate the fight between the Monk and the Goblin
void Goblin::GoblinFight(Monk &myMonk) {
    const string monsterRoomTextPath = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/MonsterRoom.txt";
    const string deathTextImage = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/YouDied.txt";
    Goblin myGoblin = Goblin();
    int fightOrDefend;
    bool isFightOver = false;

    while (!isFightOver) {
        system("cls");
        // Monk's turn
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
                        cout << endl << "Monk defeats the Goblin!" << endl << endl;
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
            }
                // Error handling for invalid input
            else if (cin.fail()) {
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
            PrintFunction::printTxtFile(monsterRoomTextPath);
            cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
                 << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
            cout << endl << "| Monster: " << myGoblin.getGoblinName() << " | HealthPoints: "
                 << myGoblin.getHealthPoints()
                 << " | AttackPoints: " << myGoblin.getAttackPoints() << " |" << std::endl << endl;
            if (Action::isSuccessful()) {
                myMonk.modifyMonkHealth(myMonk.getHealthPoints() - myGoblin.getAttackPoints());
                cout << endl << "Goblin attacks for " << myGoblin.getAttackPoints() << " points!" << endl;
                system("pause");
                system("cls");
                if (myMonk.getHealthPoints() <= 0) {
                    PrintFunction::printTxtFile(monsterRoomTextPath);
                    cout << "The Goblin defeats the Monk!" << endl;
                    system("pause");
                    system("cls");
                    PrintFunction::printTxtFile(deathTextImage);
                    system("pause");
                    system("cls");
                    // Restores Monk's health points for next game
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
}