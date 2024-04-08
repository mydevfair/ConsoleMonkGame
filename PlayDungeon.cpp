//
// Created by cfair on 29/03/2024.
//
#include "PlayDungeon.h"
#include "Monk.h"
#include "EmptyRoom.h"
#include "DungeonDelete.h"

using namespace std;

// Function to play the dungeon
void PlayDungeon::playDungeon(const vector<Room *> &dungeonArray, Monk &myMonk) {
    for (Room *room: dungeonArray) {
        room->enter(myMonk);
        DungeonDelete::deleteDungeon(room);
    }
}
