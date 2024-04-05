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

    Player *selectedMonster;
    // Switch statement to handle the random monster choice
    if (randomMonsterChoice == 1) {
        selectedMonster = new Goblin();
    }
    if (randomMonsterChoice == 2) {
        selectedMonster = new Ghost();
    }
    if (randomMonsterChoice == 3) {
        selectedMonster = new Spider();
    }

    MonsterFight::monsterFight(myMonk, *selectedMonster);
}