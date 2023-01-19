cmake_minimum_required(VERSION 3.24)
project(ex4_new)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cards)
include_directories(players)

add_executable(ex4_new
        cards/Barfight.cpp
        cards/Barfight.h
        cards/BattaleCard.cpp
        cards/BattaleCard.h
        cards/Card.cpp
        cards/Card.h
        cards/Dragon.cpp
        cards/Dragon.h
        cards/Gremlin.cpp
        cards/Gremlin.h
        cards/Mana.cpp
        cards/Mana.h
        cards/Merchant.cpp
        cards/Merchant.h
        cards/Treasure.cpp
        cards/Treasure.h
        cards/Well.cpp
        cards/Well.h
        cards/Witch.cpp
        cards/Witch.h
        players/Healer.cpp
        players/Healer.h
        players/Ninja.cpp
        players/Ninja.h
        players/Player.cpp
        players/Player.h
        players/Warrior.cpp
        players/Warrior.h
        Exception.h
        Mtmchkin.cpp
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h tool/main.cpp)
