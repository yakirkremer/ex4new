#include"Barfight.h"
Barfight::Barfight(): Card("Barfight"){}
void Barfight::applyEncounter(Player& player)const
{
    if(player.getJob().compare("Warrior")!=0)
    {
            player.damage(BARFIGHT_LOSS);
            printBarfightMessage(false);
    }
    else
    {
         printBarfightMessage(true);
    }
}