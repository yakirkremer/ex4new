#include "Merchant.h"
Merchant::Merchant():Card("Merchant"){}
void Merchant::applyEncounter(Player& player)const
{
        printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
        std::string numOfUser;
        int userNum;
    while(userNum<0|| userNum>2)
    {
            std::getline(std::cin,numOfUser);
            try
            {
                userNum=std::stoi(numOfUser);
            }
            catch(const std::invalid_argument&e)
            {
                printInvalidInput();
            }
            
    }
    if(userNum==0)
    {
        printMerchantSummary(std::cout,player.getName(),0,0);
        return;
    }
    if(userNum==1)
    {
        if(player.pay(HEAL_PRICE))
        {
                player.heal(HEAL_MERCHANT);
                printMerchantSummary(std::cout,player.getName(),1,HEAL_PRICE);
        }
        else
        {
                printMerchantInsufficientCoins(std::cout);
        }
            return;
    }
    if(userNum==2)
    {
         if(player.pay(FORCE_PRICE))
        {
                player.buff(FORCE);
                printMerchantSummary(std::cout,player.getName(),2,FORCE_PRICE);
        }
        else
        {
                printMerchantInsufficientCoins(std::cout);
        }
            return;

    }
}

    

