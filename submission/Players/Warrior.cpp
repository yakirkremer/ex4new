#include "Warrior.h"
Warrior::Warrior(std::string name,std::string job):Player(name),m_job("Warrior"){}
int Warrior::getAttackStrength()const
{
    return (m_force*2)+m_level;

}
std::string Warrior::getJob()const
{
    return m_job;
}