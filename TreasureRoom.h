//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_TREASUREROOM_H
#define CONSOLEMONKGAME_TREASUREROOM_H
#include "Monk.h"
#include "Pch.h"
#include "Room.h"

using namespace std;

class TreasureRoom : public Room {
public:
    void enter(Monk &myMonk) override;
};

#endif //CONSOLEMONKGAME_TREASUREROOM_H