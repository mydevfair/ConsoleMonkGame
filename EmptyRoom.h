//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_EMPTYROOM_H
#define CONSOLEMONKGAME_EMPTYROOM_H
#include "Room.h"
#include "Monk.h"
#include "Pch.h"

using namespace std;

class EmptyRoom : public Room{
public:
    void enter(Monk& myMonk) override;
private:
    void action(int emptyRoomChoice, Monk &myMonk);
};
#endif //CONSOLEMONKGAME_EMPTYROOM_H
