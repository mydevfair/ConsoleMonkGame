//
// Created by cfair on 29/03/2024.
//
#include "MonsterRoom.h"
#include "Pch.h"
#include "Monk.h"
#include "PrintFunction.h"
#include "MainMenu.h"
#include "Ghost.h"

using namespace std;


void MonsterRoom::enter(Monk &myMonk) {

    int randomMonsterChoice = rand() % 2 + 1;;
    string monsterRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\MonsterRoom.txt)";


    if (randomMonsterChoice == 1) {
        PrintFunction::printTxtFile(monsterRoomTextImage);
        cout << endl << "You have entered a monster room with a goblin in" << endl;
        system("pause");
        Goblin::GoblinFight(myMonk);
    }
    if (randomMonsterChoice == 2){
        PrintFunction::printTxtFile(monsterRoomTextImage);
        cout << endl << "You have entered a monster room with a Ghost in" << endl;
        system("pause");
        Ghost::GhostFight(myMonk);
    }
}