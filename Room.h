//
// Created by cfair on 30/03/2024.
//

#ifndef CONSOLEMONKGAME_ROOM_H
#define CONSOLEMONKGAME_ROOM_H


#include "Monk.h"

class Room {
public:
    virtual void enter(Monk& myMonk) = 0;

    virtual ~Room() = 0;
};


#endif //CONSOLEMONKGAME_ROOM_H
