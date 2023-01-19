#include "Well.h"
Well::Well():Card("Well"){}
void Well::applyEncounter(Player& player)const
{
    if(player.getJob().compare("Ninja")!=0)
    {   
        player.damage(HEAL_LOSS);
        printWellMessage(false);

    }
    else
    {
         printWellMessage(true);
    }
}
