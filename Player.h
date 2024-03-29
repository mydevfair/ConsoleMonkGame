//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_PLAYER_H
#define CONSOLEMONKGAME_PLAYER_H
#include "Pch.h"

using namespace std;

class Player {
public:

    Player(string playerName, int healthPoints, int attackPoints);

    virtual ~Player() = default;
    string getName() const { return playerName; }
    int getHealthPoints() const { return healthPoints; }
    int getAttackPoints() const { return attackPoints; }

private:
    string playerName{};
protected:
    int healthPoints{};
    int attackPoints{};
};


#endif //CONSOLEMONKGAME_PLAYER_H
