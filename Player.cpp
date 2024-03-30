//
// Created by cfair on 29/03/2024.
//
#include "Player.h"

// Constructor for the Player class
Player::Player(string playerName, int healthPoints, int attackPoints)
: playerName(std::move(playerName)), healthPoints(healthPoints), attackPoints(attackPoints){

}