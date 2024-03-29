//
// Created by cfair on 29/03/2024.
//
#include "PlayDungeon.h"
#include "IntialiseDungeon.h"
#include "Pch.h"
#include "PrintFunction.h"

using namespace std;

void IntialiseDungeon::intialiseDungeon(Monk& myMonk) {
    int menuChoice;
    int emptyRoom = 1;
    int monsterRoom = 2;
    int treasureRoom = 3;
    vector<int> dungeonArray;

    do {
        string difficultyTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\Difficulty.txt)";
        PrintFunction::printTxtFile(difficultyTextImage);
        cout << endl << "Welcome to the dungeon difficulty selection screen: " << endl;
        cout << endl << "Please select an option: " << endl;
        cin >> menuChoice;
        if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3) {
            cout << "Invalid input,  please enter [1] to start or [0] to exit" << endl;
            system("pause");
            system("cls");
        }
    } while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);
    system("cls");
    if (menuChoice == 1) {
        random_device rd;
        default_random_engine rng(rd());
        for (int i = 0; i < 4; ++i) {
            uniform_int_distribution<int> dist(1, 2);
            int roomType = dist(rng);
            dungeonArray.push_back(roomType);
        }
        dungeonArray.push_back(treasureRoom);
        PlayDungeon::playDungeon(dungeonArray,myMonk);
    }
    if (menuChoice == 2) {
        random_device rd;
        default_random_engine rng(rd());
        for (int i = 0; i < 9; ++i) {
            uniform_int_distribution<int> dist(1, 2);
            int roomType = dist(rng);
            dungeonArray.push_back(roomType);
        }
        dungeonArray.push_back(treasureRoom);
        PlayDungeon::playDungeon(dungeonArray, myMonk);
    }
    if (menuChoice == 3) {
        random_device rd;
        default_random_engine rng(rd());
        for (int i = 0; i < 14; ++i) {
            uniform_int_distribution<int> dist(1, 2);
            int roomType = dist(rng);
            dungeonArray.push_back(roomType);
        }
        dungeonArray.push_back(treasureRoom);
        PlayDungeon::playDungeon(dungeonArray, myMonk);
    }


    //PlayDungeon::playDungeon(dungeonArray, myMonk);
}