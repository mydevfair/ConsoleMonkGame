//
// Created by cfair on 29/03/2024.
//
#ifndef CONSOLEMONKGAME_GHOST_H
#define CONSOLEMONKGAME_GHOST_H

#include "Pch.h"
#include "Monk.h"

using namespace std;

class Ghost : public Player {
public:
    Ghost();

    string getGhostName() const;

    int takeDamage(int damage);

    [[noreturn]] static void GhostFight(Monk &myMonk);

private:
    string ghostName = "Ghost";

};
#endif //CONSOLEMONKGAME_GHOST_H