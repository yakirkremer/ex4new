#include "Witch.h"
Witch::Witch(): BattaleCard("Witch",11,10,2){}
void Witch::applyEncounter(Player& player)const
{
     if(player.getAttackStrength()>=m_force)
        {
                player.levelUp();
                player.addCoins(m_loot);
                printWinBattle(player.getName(),m_name);
                return ;
        }
            player.damage(m_damage);
            player.decreaseForce();
            printLossBattle(player.getName(),m_name);


}

