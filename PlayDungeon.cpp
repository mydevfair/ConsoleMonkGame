//
// Created by cfair on 29/03/2024.
//
#include "PlayDungeon.h"
#include "Monk.h"
#include "EmptyRoom.h"
#include "MonsterRoom.h"
#include "TreasureRoom.h"

using namespace std;

void PlayDungeon::playDungeon(const vector<int> &dungeonArray, Monk &myMonk) {
    for (int i: dungeonArray) {
        if (i == 1) {
            EmptyRoom::enter(myMonk);
        }
        if (i == 2)
            MonsterRoom::enter(myMonk);

        if (i == 3) {
            TreasureRoom::enter(myMonk);
        }
    }
}
