#include "Mtmchkin.h"
#include<fstream>

#define GREMLIN 1
#define WITCH 2
#define DRAGON 3
#define TREASURE 4
#define WELL 5
#define BARFIGHT 6
#define MANA 7
#define MERCHANT 8
#define NON -1

void printCardList(std::deque<std::shared_ptr<Card>> cardList){
    for (std::shared_ptr<Card> c1:cardList)
    {
         //std::cout<<*c1;
    }
    
}

int typeNum(std::string type)
{
    if (type == "Gremlin")
    {
        return GREMLIN;
    }
    if (type == "Witch")
    {
        return WITCH;
    }
    if (type == "Dragon")
    {
        return DRAGON;
    }
    if (type == "Treasure")
    {
        return TREASURE;
    }
    if (type == "Well")
    {
        return WELL;
    }
    if (type == "Barfight")
    {
        return BARFIGHT;
    }
    if (type == "Mana")
    {
        return MANA;
    }
    if (type == "Merchant")
    {
        return MERCHANT;
    }
    return -1;
}

Mtmchkin::Mtmchkin(const std::string& fileName)
{
    int wrongCounter = 0;
    int line=1;
    int prevline=0;
    std::ifstream infile(fileName);
     if(!infile)
     {
       throw DeckFileNotFound();
     }
     std::string type;
     //while(!infile.eof())
     while(std::getline(infile,type))
     {
        //std::getline(infile,type);
         //std::cout<<"line"<<line<<type.c_str()<<"\n";
         int numtype = typeNum(type);
         switch (numtype) {
             case GREMLIN:
                 m_card.push_back(std::shared_ptr<Card>(new Gremlin()));
                 line++;
                 break;
             case WITCH:
                 m_card.push_back(std::shared_ptr<Card>(new Witch()));
                 line++;
                 break;
             case DRAGON:
                 m_card.push_back(std::shared_ptr<Card>(new Dragon()));
                 line++;
                 break;
             case TREASURE:
                 m_card.push_back(std::shared_ptr<Card>(new Treasure()));
                 line++;
                 break;
             case WELL:
                 m_card.push_back(std::shared_ptr<Card>(new Well()));
                 line++;
                 break;
             case BARFIGHT:
                 m_card.push_back(std::shared_ptr<Card>(new Barfight()));
                 line++;
                 break;
             case MANA:
                 m_card.push_back(std::shared_ptr<Card>(new Mana()));
                 line++;
                 break;
             case MERCHANT:
                 m_card.push_back(std::shared_ptr<Card>(new Merchant()));
                 line++;
                 break;
             case NON:
                 throw DeckFileFormatError(line);




         }
         /*
         if(strcmp(type.c_str(),"Gremlin")==0)
       {
            m_card.push_back(std::shared_ptr<Card>(new Gremlin()));
            line++;
       }
       if(strcmp(type.c_str(),"Witch")==0)
       {
            m_card.push_back(std::shared_ptr<Card>(new Witch()));
            line++;

       }
       if(strcmp(type.c_str(),"Dragon")==0)
       {
             m_card.push_back(std::shared_ptr<Card>(new Dragon()));
             line++;
       }
        if(strcmp(type.c_str(),"Treasure")==0)
        {
                 m_card.push_back(std::shared_ptr<Card>(new Treasure()));
                line++;

        }
        if(strcmp(type.c_str(),"Well")==0)
        {
                 m_card.push_back(std::shared_ptr<Card>(new Well()));
                line++;
        }
        if(strcmp(type.c_str(),"Barfight")==0)
        {
                 m_card.push_back(std::shared_ptr<Card>(new Barfight()));
                line++;
        }
        if(strcmp(type.c_str(),"Mana")==0)
        {
                 m_card.push_back(std::shared_ptr<Card>(new Mana()));
                line++;
        }
          */



     }
    prevline++;

    if(line<MIN_CARD)
    {

        throw DeckFileInvalidSize();
    }


     infile.close();
     printStartGameMessage();
    int size=numOfPlayers();
    std::string word;
    for(int i=0;i<size;i++)
    {
        printInsertPlayerMessage();
        std::getline(std::cin,word);
        addPlayer(word);
    }
    m_numOfRound=0;
    m_nextCard =  m_card.begin();
}
int Mtmchkin::getNumberOfRounds()const
{
        return m_numOfRound;
}
void Mtmchkin::playRound()
{
    m_numOfRound++;

    printRoundStartMessage(getNumberOfRounds());
        for(std::deque <std::shared_ptr<Player>>::iterator i=m_player.begin();i!=m_player.end();++i)
        {
            printTurnStartMessage((*i)->getName());
            if(m_nextCard == m_card.end())
            {
                m_nextCard = m_card.begin();
            }

            (*m_nextCard)->applyEncounter(**i);

            m_nextCard++;

        }

        sort();
        if(isGameOver())
        {
            printGameEndMessage();

        }


    

}
void Mtmchkin::sort()
{
    std::deque <std::shared_ptr<Player>>::iterator i=m_player.begin();

    while(i!=m_player.end())

    {

        if((*i)->getHP()<=0)
        {

            m_loser.push_back(*i);
            i = m_player.erase(i);
            //i++;
        }
        else if((*i)->getLevel()>=10)
        {

            m_winner.push_back(*i);
            i = m_player.erase(i);
            //i++;
        } else
        {
            ++i;
        }

    }

}
bool Mtmchkin::isGameOver()const
{
        if(m_player.empty())
        {
            return true;
        }
        return false;
}

void Mtmchkin::printLeaderBoard()const
{
    int ranking = 1;
    printLeaderBoardStartMessage();
    for(std::shared_ptr<Player> p1:m_winner)
    {
        printPlayerLeaderBoard(ranking, *p1);
        ranking++;
        //std::cout<<(*p1);
    }
    for(std::shared_ptr<Player> p1:m_player)
    {
        //std::cout<<(*p1);
        printPlayerLeaderBoard(ranking, *p1);
        ranking++;
    }
    //std::deque<std::shared_ptr<Player>>::reverse_iterator
    for( std::deque<std::shared_ptr<Player>>::const_reverse_iterator  i=m_loser.rbegin();i!=m_loser.rend();++i)
    {
        //std::cout<<(**i);
        printPlayerLeaderBoard(ranking, **i);
        ranking++;
    }
}






int Mtmchkin::numOfPlayers()
{
       std::string numOfUser;
        int userNum=0;
    while(userNum<2|| userNum>6)//להחליף לקבועים
    {
            printEnterTeamSizeMessage();
            std::getline(std::cin,numOfUser);
            try
            {
                userNum=std::stoi(numOfUser);
                if(userNum<2|| userNum>6)
                {
                     printInvalidTeamSize();
                }
            }
            catch(const std::invalid_argument&e)
            {
                 printInvalidTeamSize();
              
            }
    }
        return userNum;
}
bool Mtmchkin::nameOfPlayer(std::string name)
{
    if(name.length()>15)  //לשנות לקבוע
    {
        return false;
    }
    for(char &check:name)
    {
        if(!isalpha(check))
        {
            return false;
        }
    }
    return true;
}
bool Mtmchkin::isExist(std::string name,std::string type)
{
    for(std::shared_ptr<Player>check:m_player)
    {
            if(check->getName()==name && check->getJob()==type)
            {
                    return true;
            }
    }
        return false;
}


void  Mtmchkin::addPlayer(std::string playerInfo)
{
    std::string name;
    std::string type;
    while(true)
    {
        name=playerInfo.substr(0,playerInfo.find(" "));
        type=playerInfo.substr(playerInfo.find(" ")+1,playerInfo.length());
        if(!isExist(name,type)&&nameOfPlayer(name))
        {
            if(type=="Warrior")
            {
                m_player.push_back(std::shared_ptr<Player>(new Warrior(name,type)));
                    return;

            }
            
            if(type=="Healer")
            {
                m_player.push_back(std::shared_ptr<Player>(new Healer(name,type)));
                    return;

            }
            
            if(type=="Ninja")
            {
                m_player.push_back(std::shared_ptr<Player>(new Ninja(name,type)));
                    return;

            }
                printInvalidClass();
        
        }
        else
        {
            printInvalidName();
            
        }
        std::getline(std::cin,playerInfo);




    }
}


