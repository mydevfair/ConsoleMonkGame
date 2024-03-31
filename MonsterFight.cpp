//
// Created by cfair on 31/03/2024.
//

#include "MonsterFight.h"
#include "Pch.h"
#include "PrintFunction.h"
#include "Monk.h"
#include "Action.h"
#include "MainMenu.h"

void MonsterFight::monsterFight(Monk &myMonk, Player& player) {
    const string monsterRoomTextPath = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/MonsterRoom.txt";
    const string deathTextImage = "C:/Users/cfair/CLionProjects/ConsoleMonkGame/Text_Files/YouDied.txt";
    int fightOrDefend;
    bool isFightOver = false;

    while (!isFightOver) {
        system("cls");
        // Monk's turn
        do {
            PrintFunction::printTxtFile(monsterRoomTextPath);
            cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
                 << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
            cout << endl << "| Monster: " << player.getName() << " | HealthPoints: "
                 << player.getHealthPoints()
                 << " | AttackPoints: " << player.getAttackPoints() << " |" << endl << endl;
            cout << "Your turn!" << endl;
            cout << "Do you want to fight (1) or defend (2)? ";
            cin >> fightOrDefend;
            if (fightOrDefend == 1) {
                if (Action::isSuccessful()) {
                    player.takeDamage(myMonk.getAttackPoints());
                    cout << "Monk attacks for " << myMonk.getAttackPoints() << " points!" << endl;
                    system("pause");
                    system("cls");
                    if (player.getHealthPoints() <= 0) {
                        PrintFunction::printTxtFile(monsterRoomTextPath);
                        cout << endl << "Monk defeats " << player.getName() << endl << endl;
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
            cout << endl << "| Monster: " << player.getName() << " | HealthPoints: "
                 << player.getHealthPoints()
                 << " | AttackPoints: " << player.getAttackPoints() << " |" << std::endl << endl;
            cout << "Monster's turn!" << endl;
            if (Action::isSuccessful()) {
                myMonk.modifyMonkHealth(myMonk.getHealthPoints() - player.getAttackPoints());
                cout << endl << player.getName() << " attacks for " << player.getAttackPoints() << " points!" << endl;
                system("pause");
                system("cls");
                if (myMonk.getHealthPoints() <= 0) {
                    PrintFunction::printTxtFile(monsterRoomTextPath);
                    cout << "The " << player.getName() << " defeats the Monk!" << endl;
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
                cout << player.getName() << " attack missed!" << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

