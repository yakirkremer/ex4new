#ifndef GREMLIN_H
#define GREMLIN_H
#include "BattaleCard.h"
class Gremlin:public BattaleCard
{
    public:
    Gremlin();
     Gremlin(const Gremlin& other)=default;
    Gremlin& operator=(const Gremlin& other)=default;
    ~Gremlin()=default;
     void applyEncounter(Player& player)const override;

};
#endif