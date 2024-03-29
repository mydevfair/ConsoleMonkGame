//
// Created by cfair on 29/03/2024.
//
#include "Monk.h"
#include "Pch.h"

using namespace std;

static Monk* monkInstance = nullptr;

Monk::Monk(const string& monkName, string description)
    : Player(monkName, 15, 3), monkName(monkName), description(description)
{

}
void Monk::setMonkName(const string& name) {
    monkName = name;
}
string Monk::getMonkName() const {
    return monkName;
}
string Monk::getMonkDescription() const{
    return description;
}
void Monk::setMonkDescription(string desc) {
    description = std::move(desc);
};
Monk* Monk::getMonkInstance(){
    if (monkInstance == nullptr){
        monkInstance = new Monk("Default", "Description");
    }
    return monkInstance;
}
Monk::~Monk(){
    if (monkInstance == this){
        delete monkInstance;
        monkInstance = nullptr;
    }
}
int Monk::restoreMonkHealthPoints(){
    return healthPoints = 15;
}

int Monk::modifyMonkHealth(int damage) {
    return healthPoints = damage;
}


