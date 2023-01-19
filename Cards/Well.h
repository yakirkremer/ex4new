#ifndef WELL_H
#define WELL_H
#include "Card.h"
int const HEAL_LOSS=10;
class Well: public Card
{
    public:
        Well();
         Well(const Well& other)=default;
         Well& operator=(const Well& other)=default;
        ~Well()=default;
        void applyEncounter(Player& player)const override;
};
#endif