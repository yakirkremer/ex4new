#include "Dragon.h"
Dragon::Dragon(): BattaleCard("Dragon",25,-1,1000){}
void Dragon::printCard(std::ostream& os)const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot,true);
    printEndOfCardDetails(os);

}
void Dragon::applyEncounter(Player& player)const
{
        if(player.getAttackStrength()>=m_force)
        {
                player.levelUp();
                player.addCoins(m_loot);
                printWinBattle(player.getName(),m_name);
                return ;
        }
            player.damage(player.getHP());
            printLossBattle(player.getName(),m_name);

}