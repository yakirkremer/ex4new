#ifndef MANA_H
#define MANA_H
#include "Card.h"
int const HEAL=10;
class Mana: public Card
{
    public:
         Mana();
         Mana(const Mana& other)=default;
         Mana& operator=(const Mana& other)=default;
        ~Mana()=default;
        void applyEncounter(Player& player)const override;
    
};
#endif