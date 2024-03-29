//
// Created by cfair on 29/03/2024.
//

#ifndef CONSOLEMONKGAME_MONK_H
#define CONSOLEMONKGAME_MONK_H
#include "Pch.h"
#include "Player.h"

using namespace std;

class Monk : public Player{
public:
    Monk(const string& monkName, string description);
    void setMonkName(const string&);
    string getMonkName() const;
    void setMonkDescription(string);
    string getMonkDescription() const;
    int modifyMonkHealth(int);

    static Monk *getMonkInstance();

    ~Monk() override;

    int restoreMonkHealthPoints();

private:
    string description;
    string monkName;

};


#endif //CONSOLEMONKGAME_MONK_H
