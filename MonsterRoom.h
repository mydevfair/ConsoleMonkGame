//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_MONSTERROOM_H
#define CONSOLEMONKGAME_MONSTERROOM_H
#include "Pch.h"
#include "Monk.h"
#include "Goblin.h"
#include "Room.h"

using namespace std;

class MonsterRoom : public Room{
public:
    void enter(Monk &myMonk) override;
};


#endif //CONSOLEMONKGAME_MONSTERROOM_H
