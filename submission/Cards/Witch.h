#ifndef WITCH_H
#define WITCH_H
#include "BattaleCard.h"
class Witch:public BattaleCard
{
    public:
    Witch();
     Witch(const Witch& other)=default;
    Witch& operator=(const Witch& other)=default;
    ~Witch()=default;
    void applyEncounter(Player& player)const override;




};
#endif