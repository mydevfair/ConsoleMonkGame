//
// Created by cfair on 29/03/2024.
//
#include "MonsterRoom.h"
#include "Pch.h"
#include "Monk.h"
#include "PrintFunction.h"
#include "MainMenu.h"
#include "Ghost.h"
#include "Action.h"
#include "MonsterFight.h"
#include "Player.h"

using namespace std;
// Function to enter the monster room
void MonsterRoom::enter(Monk &myMonk) {
    // Randomly select a monster to fight
    int randomMonsterChoice = Action::getRandomInt();
    string monsterRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\MonsterRoom.txt)";
    const vector<Player*> monsterArray = {new Goblin(), new Ghost()};

    Player* selectedMonster;

    if (randomMonsterChoice == 1) {
        selectedMonster = monsterArray[0];
    }
    if (randomMonsterChoice == 2) {
        selectedMonster = monsterArray[1];
    }

    MonsterFight::monsterFight(myMonk, *selectedMonster);













    // Switch statement to handle the random monster choice
//    if (randomMonsterChoice == 1) {
//        PrintFunction::printTxtFile(monsterRoomTextImage);
//        cout << endl << "You have entered a monster room with a goblin in" << endl;
//        cout << endl << "Get Ready To Fight!!!" << endl << endl;
//        system("pause");
//        Goblin::GoblinFight(myMonk);
//    }
//    if (randomMonsterChoice == 2){
//        PrintFunction::printTxtFile(monsterRoomTextImage);
//        cout << endl << "You have entered a monster room with a Ghost in" << endl;
//        cout << endl << "Get Ready To Fight!!!" << endl << endl;
//        system("pause");
//        Ghost::GhostFight(myMonk);
//    }
}