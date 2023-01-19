#include "Ninja.h"
Ninja::Ninja(std::string name,std::string job):Player(name),m_job("Ninja"){}
Ninja& Ninja::addCoins(const int coins)
{
        this->m_coins+=(coins*2);
        return *this;
}
std::string Ninja::getJob()const
{
        return m_job;
}