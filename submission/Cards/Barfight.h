#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "Card.h"
int const BARFIGHT_LOSS=10;
class Barfight: public Card
{
    public:
        Barfight();
        Barfight(const Barfight& other)=default;
        Barfight& operator=(const Barfight& other)=default;
        ~Barfight()=default;
        void applyEncounter(Player& player)const override;
};
#endif