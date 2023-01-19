#include "Card.h"
Card::Card(std::string name):m_name(name){}
    

    

void Card::printCard(std::ostream& os)const
{
    printCardDetails(os,m_name);
     printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream &os, Card& card)
{
    
    card.printCard(os);
    return os;
}
