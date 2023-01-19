#ifndef MERCHANT_H
#define MERCHANT_H
#include "Card.h"
int const HEAL_MERCHANT=1;
int const FORCE=1;
int const HEAL_PRICE=5;
int const FORCE_PRICE=10;
class Merchant: public Card
{
    public:
    Merchant();
    Merchant(const Merchant& other)=default;
    Merchant& operator=(const Merchant& other)=default;
    ~Merchant()=default;
     void applyEncounter(Player& player)const override;
    
};
#endif