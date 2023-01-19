//
// Created by yakir on 1/18/2023.
//

#include "../Mtmchkin.h"
int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game1("..\\deck.txt");
    while(!game1.isGameOver()&& game1.getNumberOfRounds()<MAX_NUMBER_OF_ROUNDS)
    {
            game1.playRound();  
    }
     game1.printLeaderBoard();
}