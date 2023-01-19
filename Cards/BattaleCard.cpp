#include"BattaleCard.h"
BattaleCard::BattaleCard(std::string name,int force,int damage,int loot):Card(name),m_force(force),m_damage(damage),m_loot(loot){}

void BattaleCard::printCard(std::ostream& os)const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}
