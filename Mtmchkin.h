#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include<string>
#include<vector>
#include<map>
#include<memory>
#include<deque>
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "utilities.h"
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Mtmchkin.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>

int const MIN_CARD=5;




class Mtmchkin{
    int m_numOfRound;
    std::deque<std::shared_ptr<Player>> m_player;
    std::deque<std::shared_ptr<Card>> m_card;
    std::deque<std::shared_ptr<Player>> m_winner;
    std::deque<std::shared_ptr<Player>> m_loser;
    std::deque<std::shared_ptr<Card>>::iterator m_nextCard;
    bool isExist(std::string name,std::string type);
    bool nameOfPlayer(std::string name);
    void addPlayer(std::string playerInfo);
    void sort();
    int numOfPlayers();

public:


    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string&fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    
};


#endif /* MTMCHKIN_H_ */