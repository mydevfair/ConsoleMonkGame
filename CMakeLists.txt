cmake_minimum_required(VERSION 3.23)
project(ConsoleMonkGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConsoleMonkGame main.cpp
        Pch.cpp
        Player.cpp
        Monk.cpp
        Goblin.cpp
        MonsterRoom.cpp
        IntialiseDungeon.cpp
        EmptyRoom.cpp
        TreasureRoom.cpp
        PlayDungeon.cpp
        MainMenu.cpp
        PrintFunction.cpp
        )
