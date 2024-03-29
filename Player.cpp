//
// Created by cfair on 29/03/2024.
//

#include "Player.h"

Player::Player(string playerName, int healthPoints, int attackPoints)
: playerName(std::move(playerName)), healthPoints(healthPoints), attackPoints(attackPoints){

}