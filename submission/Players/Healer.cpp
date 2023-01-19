#include "Healer.h"
Healer::Healer(std::string name,std::string job):Player(name),m_job("Healer"){}
Healer& Healer::heal(const int heal)
 {
   //this->Player::heal(heal);
   
   this->m_hp+= heal*2;
   if(m_hp>m_maxhp)
   {
        m_hp=m_maxhp;
   }
   return *this;
 }
 std::string Healer::getJob()const
 {
    return m_job;
 }

