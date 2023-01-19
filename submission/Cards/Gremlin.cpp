#include "Gremlin.h"
Gremlin::Gremlin(): BattaleCard("Gremlin",5,10,2){}
void::Gremlin::applyEncounter(Player& player)const
{
    if(player.getAttackStrength()>=m_force)
        {
                player.levelUp();
                player.addCoins(m_loot);
                printWinBattle(player.getName(),m_name);
                return ;
        }
            player.damage(m_damage);
            printLossBattle(player.getName(),m_name);

}


