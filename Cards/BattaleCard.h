#ifndef BattaleCard_H
#define BattaleCard_H
#include "Card.h"
class BattaleCard:public Card
{
    protected:
    int m_force;
    int m_damage;
    int m_loot;
    public:
    virtual void applyEncounter(Player& player)const=0;
    BattaleCard(std::string name,int force,int damage,int loot);
     virtual void printCard(std::ostream&)const override;
     virtual ~BattaleCard()=default;
     

};
#endif