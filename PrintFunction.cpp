//
// Created by cfair on 29/03/2024.
//
#include "PrintFunction.h"

// Function to print a text file
void PrintFunction::printTxtFile(const string &file) {
    string line;
    ifstream inFile;
    inFile.open(file);
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error! File not found!" << endl;
    }
    inFile.close();
}

