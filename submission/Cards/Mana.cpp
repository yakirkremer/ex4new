#include"Mana.h"
Mana::Mana():Card("Mana"){}
void Mana::applyEncounter(Player& player)const
{
    if(player.getJob() == "Healer")
    {
        player.heal(HEAL);
         printManaMessage(true);
    }
    else
    {
        printManaMessage(false);
    }
}