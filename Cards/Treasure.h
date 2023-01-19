#ifndef TREASURE_H
#define TREASURE_H
#include "Card.h"
int const TREASURE=10;
class Treasure: public Card
{
    public:
        Treasure();
        Treasure(const Treasure& other)=default;
        Treasure& operator=(const Treasure& other)=default;
        ~Treasure()=default;
        void applyEncounter(Player& player)const override;
};
#endif
