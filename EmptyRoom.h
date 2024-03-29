//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_EMPTYROOM_H
#define CONSOLEMONKGAME_EMPTYROOM_H

#include "EmptyRoom.h"
#include "Monk.h"
#include "Pch.h"

using namespace std;

class EmptyRoom {
public:
    static void enter(Monk& myMonk);

    static void action(int emptyRoomChoice, Monk &myMonk);
};


#endif //CONSOLEMONKGAME_EMPTYROOM_H
