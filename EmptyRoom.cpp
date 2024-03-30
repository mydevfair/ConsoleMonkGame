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
    while (true) {
        PrintFunction::printTxtFile(emptyRoomTextImage);
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl;
        cout << endl << "You entered an empty room. Please Select Your Next Move." << endl << endl;
        cout << "Press [1] To Restore Your Health Or [2] To Continue" << endl << endl;
        try {
            cin >> emptyRoomChoice;
            if (cin.fail()) {
                throw runtime_error("Invalid input. Please enter 1 or 2.");
            }
            if (emptyRoomChoice != 1 && emptyRoomChoice != 2) {
                throw runtime_error("Invalid choice. Please enter 1 or 2.");
            }
            break; // Valid input received, exit the loop
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
        }
    }
    action(emptyRoomChoice, myMonk);
    system("cls");
}

void EmptyRoom::action(int emptyRoomChoice, Monk &myMonk) {
    if (emptyRoomChoice != 1 && emptyRoomChoice != 2) {
        cout << "Invalid input,  please enter [1] to Pray or [2] to continue game " << endl << endl;
        system("pause");
        system("cls");
        enter(myMonk);
    }
    if (emptyRoomChoice == 1) {
        system("cls");
        PrintFunction::printTxtFile(emptyRoomTextImage);
        myMonk.restoreMonkHealthPoints();
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl << endl;
        cout << "Monk: " << myMonk.getMonkName() << " HealthPoints Restored" << endl << endl;
        system("pause");
    }
    if (emptyRoomChoice == 2) {
        system("cls");
        PrintFunction::printTxtFile(emptyRoomTextImage);
        myMonk.restoreMonkHealthPoints();
        cout << endl << "| Monk: " << myMonk.getMonkName() << " | HealthPoints: " << myMonk.getHealthPoints()
             << " | AttackPoints: " << myMonk.getAttackPoints() << " |" << endl << endl;
        cout << "You Have Chosen To Continue" << endl << endl;
        system("pause");
    }
}