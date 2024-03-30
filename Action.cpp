//
// Created by cfair on 30/03/2024.
//
#include "Pch.h"
#include "Action.h"

bool Action::isSuccessful() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    int randomNumber = rand() % 10;

    return randomNumber % 2 == 0;
}

int Action::getRandomInt() {
    srand(static_cast<unsigned int>(time(nullptr))); // Uncomment if needed
    return rand() % 2 + 1;
}