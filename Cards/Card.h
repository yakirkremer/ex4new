#ifndef CARD_H
#define CARD_H
#include "../utilities.h"
#include "../Players/Player.h"
#include "../Players/Warrior.h"
#include "../Players/Healer.h"
#include "../Players/Ninja.h"
class Card
{
    protected:
    std::string m_name;
    public:
    Card(std::string name);
    Card(const Card& other)=default;
    Card& operator=(const Card& other)=default;
    virtual~Card()=default;
    friend std::ostream& operator<<(std::ostream &os, Card& card);
     virtual void printCard(std::ostream & os)const;
    virtual void applyEncounter(Player& player)const=0;
};
#endif