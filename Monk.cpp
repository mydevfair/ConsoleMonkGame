//
// Created by cfair on 29/03/2024.
//
#include "Monk.h"
#include "Pch.h"

using namespace std;

// Static instance of the Monk class
static Monk* monkInstance = nullptr;
// Constructor for the Monk class
Monk::Monk(const string& monkName, string description)
    : Player(monkName, 15, 3), monkName(monkName), description(description)
{

}
// Setter and getter for the monk name
void Monk::setMonkName(const string& name) {
    monkName = name;
}
string Monk::getMonkName() const {
    return monkName;
}
// Setter and getter for the monk description
string Monk::getMonkDescription() const{
    return description;
}
void Monk::setMonkDescription(string desc) {
    description = std::move(desc);
};
// Function to get the monk instance
Monk* Monk::getMonkInstance(){
    if (monkInstance == nullptr){
        monkInstance = new Monk("Default", "Description");
    }
    return monkInstance;
}
// Destructor for the Monk class
Monk::~Monk(){
    if (monkInstance == this){
        delete monkInstance;
        monkInstance = nullptr;
    }
}
// Function to restore the monk's health points
int Monk::restoreMonkHealthPoints(){
    return healthPoints = 15;
}
// Function to modify the monk's health points
int Monk::modifyMonkHealth(int damage) {
    return healthPoints = damage;
}


