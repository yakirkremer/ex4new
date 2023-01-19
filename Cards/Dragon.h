#ifndef DRAGON_H
#define DRAGON_H
#include "BattaleCard.h"

class Dragon:public BattaleCard
{
    public:
        Dragon();
        Dragon(const Dragon& other)=default;
        Dragon& operator=(const Dragon& other)=default;
        ~Dragon()=default;
        void printCard(std::ostream&)const override;
        void applyEncounter(Player& player)const override;




};
#endif