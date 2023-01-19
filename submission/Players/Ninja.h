#ifndef NINJA_H
#define NINJA_H
#include "Player.h"
class Ninja: public Player
{
        std::string m_job;
    public:
            Ninja(std::string name,std::string job = "Ninja");
            Ninja( const Ninja& other)=default;
            ~Ninja()=default;
             Ninja& operator=(const Ninja& other)=default;
             Ninja&addCoins(const int coins)override;
            std::string getJob()const override;

};
#endif
