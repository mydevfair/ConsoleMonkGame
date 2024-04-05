//
// Created by cfair on 29/03/2024.
//
#include "MonsterRoom.h"
#include "Pch.h"
#include "Monk.h"
#include "MainMenu.h"
#include "Ghost.h"
#include "Action.h"
#include "MonsterFight.h"
#include "Player.h"
#include "Goblin.h"
#include "Spider.h"

using namespace std;

// Function to enter the monster room
void MonsterRoom::enter(Monk &myMonk) {
    // Randomly select a monster to fight
    int randomMonsterChoice = Action::getRandomInt();
    string monsterRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\MonsterRoom.txt)";
    const vector<Player *> monsterArray = {new Goblin(), new Ghost(), new Spider()};

    Player *selectedMonster;
    // Switch statement to handle the random monster choice
    if (randomMonsterChoice == 1) {
        selectedMonster = monsterArray[0];
    }
    if (randomMonsterChoice == 2) {
        selectedMonster = monsterArray[1];
    }
    if (randomMonsterChoice == 3) {
        selectedMonster = monsterArray[2];
    }

    MonsterFight::monsterFight(myMonk, *selectedMonster);
}