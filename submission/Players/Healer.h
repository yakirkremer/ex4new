#ifndef HEALER_H
#define HEALER_H
#include "Player.h"
class Healer: public Player
{
            std::string m_job;
    public:
            Healer(std::string name,std::string job= "Healer");
            Healer( const Healer& other)=default;
            ~Healer()=default;
            Healer& operator=(const Healer& other)=default;
            Healer&heal(const int hp)override;
             std::string getJob()const override;



};
#endif