//
// Created by cfair on 29/03/2024.
//

#include "EmptyRoom.h"
#include "Monk.h"
#include "Pch.h"
#include "PrintFunction.h"

using namespace std;

string emptyRoomTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\EmptyRoom.txt)";

void EmptyRoom::enter(Monk &myMonk) {
    int emptyRoomChoice;
    PrintFunction::printTxtFile(emptyRoomTextImage);
    cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
         << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
    cout << endl << "You entered an empty room. Please Select Your Next Move." << endl;
    cout << "Press [1] To Restore Your Health Or [2] To Continue" << endl;
    cin >> emptyRoomChoice;
    action(emptyRoomChoice, myMonk);
    system("cls");
}
void EmptyRoom::action(int emptyRoomChoice, Monk &myMonk) {
    if (emptyRoomChoice != 1 && emptyRoomChoice != 2) {
        cout << "Invalid input,  please enter [1] to Pray or [2] to continue game " << endl;
        system("pause");
        system("cls");
        enter(myMonk);
    }
    if (emptyRoomChoice == 1) {
        system("cls");
        PrintFunction::printTxtFile(emptyRoomTextImage);
        myMonk.restoreMonkHealthPoints();
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << "Monk: " << myMonk.getMonkName() << " HealthPoints Restored" << endl;
        system("pause");
    }
    if (emptyRoomChoice == 2) {

    }
}