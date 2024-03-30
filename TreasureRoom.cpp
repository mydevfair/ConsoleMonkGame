//
// Created by cfair on 29/03/2024.
//
#include "TreasureRoom.h"
#include "Monk.h"
#include "Pch.h"
#include "PrintFunction.h"
#include "IntialiseDungeon.h"

using namespace std;

// Constructor for the TreasureRoom class
void TreasureRoom::enter(Monk &myMonk) {
    int treasureRoomChoice;
    string treasureRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\TresureRoom.txt)";
    PrintFunction::printTxtFile(treasureRoomTextImage);
    cout << endl << "You have reached Treasure room." << endl << endl;
    cout << "Monk " << myMonk.getMonkName() << " Has Completed The Dungeon" << endl << endl;
    cout << "Please press [1] to play again or [0] to exit" << endl;
    cin >> treasureRoomChoice;
    // Error handling for invalid input
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input,  please enter [1] to play again or [0] to exit game " << endl;
        system("pause");
        system("cls");
        enter(myMonk);
    }
    if (treasureRoomChoice != 0 && treasureRoomChoice != 1){
        cout << "Invalid input,  please enter [1] to play again or [0] to exit game " << endl;
        system("pause");
        system("cls");
        enter(myMonk);
    }
    // If the user selects to exit the game
    if (treasureRoomChoice == 0){
        cout << "Goodbye" << endl;
        exit(0);
    }
    // If the user selects to play the game again
    if (treasureRoomChoice == 1){
        system("cls");
        myMonk.restoreMonkHealthPoints();
        IntialiseDungeon::intialiseDungeon(myMonk);
    }
}
