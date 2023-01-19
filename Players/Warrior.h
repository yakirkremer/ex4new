#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"
class Warrior: public Player
{
            std::string m_job;
    public:
            Warrior(std::string name,std::string job = "Warrior");
             Warrior( const  Warrior& other)=default;
            ~Warrior()=default;
            Warrior& operator=(const Warrior& other)=default;
            int getAttackStrength()const override;
            std::string getJob()const override;

};
#endif
