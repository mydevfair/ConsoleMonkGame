//
// Created by cfair on 29/03/2024.
//
#include "PlayDungeon.h"
#include "IntialiseDungeon.h"
#include "Pch.h"
#include "PrintFunction.h"

using namespace std;

// Function to intialise the dungeon based on the difficulty selected by the user
void IntialiseDungeon::intialiseDungeon(Monk &myMonk) {
    int menuChoice;
    vector<Room *> dungeonArray;
    // Display the difficulty selection screen
    do {
        string difficultyTextImage = R"(C:\Users\cfair\CLionProjects\ConsoleMonkGame\Text_Files\Difficulty.txt)";
        PrintFunction::printTxtFile(difficultyTextImage);
        cout << endl << "Welcome to the dungeon difficulty selection screen: " << endl;
        cout << endl << "Please select an option: " << endl << endl;

        // Get user input with error handling
        if (!(cin >> menuChoice)) {
            // Handle failed integer extraction
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input, please enter a number (1, 2, or 3)." << endl;
        } else {
            // Check for leftover input *and* reset cin state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard leftover and reset
            string leftover;
            getline(cin, leftover); // Check for leftover again (optional)
            if (!leftover.empty()) {
                cout << "Invalid input, please enter a single number (1, 2, or 3)." << endl;
            }
        }

    } while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

    system("cls");
    // Switch statement to handle the user's choice
    switch (menuChoice) {
        case 1: {
            // Easy difficulty
            random_device rd;
            default_random_engine engine(rd());

            for (int i = 0; i < 4; ++i) {
                uniform_int_distribution<int> dist(1, 2);  // Generate between 1 and 2
                int roomType = dist(engine);
                if (roomType == 1) {
                    dungeonArray.push_back(new EmptyRoom());
                } else {
                    dungeonArray.push_back(new MonsterRoom());
                }
            }
            dungeonArray.push_back(new TreasureRoom());
            PlayDungeon::playDungeon(dungeonArray, myMonk);
            break;
        }
        case 2: {
            // Medium difficulty
            random_device rd;
            default_random_engine engine(rd());

            for (int i = 0; i < 9; ++i) {
                uniform_int_distribution<int> dist(1, 2);  // Generate between 1 and 2
                int roomType = dist(engine);
                if (roomType == 1) {
                    dungeonArray.push_back(new EmptyRoom());
                } else {
                    dungeonArray.push_back(new MonsterRoom());
                }
            }
            dungeonArray.push_back(new TreasureRoom());
            PlayDungeon::playDungeon(dungeonArray, myMonk);
            break;
        }
        case 3: {
            // Hard difficulty
            random_device rd;
            default_random_engine engine(rd());

            for (int i = 0; i < 14; ++i) {
                uniform_int_distribution<int> dist(1, 2);  // Generate between 1 and 2
                int roomType = dist(engine);
                if (roomType == 1) {
                    dungeonArray.push_back(new EmptyRoom());
                } else {
                    dungeonArray.push_back(new MonsterRoom());
                }
            }
            dungeonArray.push_back(new TreasureRoom());
            PlayDungeon::playDungeon(dungeonArray, myMonk);
            break;
        }
        // Handle unexpected menuChoice (shouldn't happen here, but good practice)
        default: {
            // Handle unexpected menuChoice (shouldn't happen here, but good practice)
            cout << "An unexpected error occurred. Please restart the program." << endl;
            break;
        }
    }
}