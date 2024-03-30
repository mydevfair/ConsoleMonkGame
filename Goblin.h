//
// Created by cfair on 29/03/2024.
//
#ifndef CONSOLEMONKGAME_GOBLIN_H
#define CONSOLEMONKGAME_GOBLIN_H
#include "Pch.h"
#include "Player.h"
#include "Monk.h"

using namespace std;

class Goblin : public Player{
public:
    Goblin();
    string getGoblinName() const;

    int takeDamage(int damage);

    static void GoblinFight(Monk &myMonk);
private:
    string goblinName = "Goblin";

};
#endif //CONSOLEMONKGAME_GOBLIN_H