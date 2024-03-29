//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_PLAYDUNGEON_H
#define CONSOLEMONKGAME_PLAYDUNGEON_H
#include "Pch.h"
#include "IntialiseDungeon.h"
#include "EmptyRoom.h"
#include "MonsterRoom.h"
#include "TreasureRoom.h"
#include "Monk.h"

using namespace std;

class PlayDungeon {
public:
    static void playDungeon(const vector<int> &dungeonArray, Monk &myMonk);
};


#endif //CONSOLEMONKGAME_PLAYDUNGEON_H
