//
// Created by cfair on 29/03/2024.
//
#include "MainMenu.h"
#include "Monk.h"
#include "PrintFunction.h"
#include "IntialiseDungeon.h"

using namespace std;


void MainMenu::MainMenuChoice() {
    int menuChoice;
    string menuTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\Intro.txt)";
    do {
        PrintFunction::printTxtFile(menuTextImage);
        cout << "Welcome Player! Please press [1] to start game or [0] to exit" << endl << endl;
        cin >> menuChoice;
        cout << endl;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Invalid input, please enter 1 to start or 0 to exit" << endl << endl;
            system("pause");
            system("cls");
            MainMenuChoice();
        } else if (menuChoice != 0 && menuChoice != 1) {
            cout << endl << "Invalid input, please enter 1 to start or 0 to exit" << endl << endl;
            system("pause");
            system("cls");
            MainMenuChoice();
        }
        system("pause");
        system("cls");
    } while (menuChoice != 0 && menuChoice != 1 && !cin.fail());

    if (menuChoice == 0) {
        cout << "Goodbye" << endl;
        exit(0);
    }
    if (menuChoice == 1) {
        system("cls");
        Monk *myMonk = Monk::getMonkInstance();
        string monkName;
        string monkDescription;
        PrintFunction::printTxtFile(menuTextImage);
        cout << "Please Enter Monk's Name: " << endl << endl;
        getline(cin >> ws, monkName);
        cout << endl << "Please Enter The Monk's description: " << endl << endl;
        getline(cin >> ws, monkDescription);
        myMonk->setMonkName(monkName);
        myMonk->setMonkDescription(monkDescription);
        system("cls");
        PrintFunction::printTxtFile(menuTextImage);
        cout << "Welcome, Monk " << myMonk->getMonkName() << "!" << endl << endl;
        cout << "Monk Description: " << myMonk->getMonkDescription() << "!" << endl << endl;
        system("pause");
        system("cls");
        IntialiseDungeon::intialiseDungeon(*myMonk);
        system("pause");
    }
}


