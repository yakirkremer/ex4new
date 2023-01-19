#include "../utilities.h"
#include "Player.h"
Player::Player(std::string name)
{
    m_name=name;
     m_maxhp=MAX_HP;
     m_force=START_FORCE;
     m_hp=MAX_HP;
     m_level=START_LEVEL;
     m_coins=START_COINS;
}

 Player& Player::levelUp()
{
    if(this->m_level >=10)
    {
     return *this;
    }

     this->m_level++;
     return *this;
}
 int  Player::getLevel()const
 {
        return this->m_level;

 }
 Player& Player::buff(const int force)
 {
    if(force<0)
    {
        return *this;
    }
    this->m_force=this->m_force+force;
    return *this;
 }
 Player& Player::heal(const int heal)
 {
    if(this->m_hp >= this->m_maxhp || heal<0)
        {
            return *this;
        }
        this->m_hp= this->m_hp +heal;
        if(this->m_hp>this->m_maxhp)
        {
            this->m_hp=this->m_maxhp;
        }
        return *this;
 }

 Player& Player::damage(const int damage)
 {
    if(damage<0)
    {
            return *this;
    }
    this->m_hp= this->m_hp-damage;
    if(this->m_hp <0)
    {
        this->m_hp=0;
    }
    return *this;
 }
  bool Player::isKnockedOut()const
  {
    if(this->m_hp==0)
    {
         return true;
    }
    return false;
  }
   Player& Player::addCoins( const int coins)
   {
        if(coins<0)
        {
            return *this;
        }
        this->m_coins=this->m_coins+coins;
        return *this;

   }
    bool Player::pay( const int pay)
    {
        if(pay<0)
        {
            return true;
        }
        if(this->m_coins<pay)
        {
            return false;
        }
        this->m_coins=this->m_coins-pay;
        return true;
    }
    int Player:: getAttackStrength()const
    {
        return this->m_level+this->m_force;
    }
    
    std::ostream& operator<<(std::ostream &os, const Player& player)
    {
        printPlayerDetails(os,player.m_name,player.getJob(),player.m_level,player.m_force,player.m_hp,player.m_coins);
        return os;
    }
    std::string Player::getName()const
    {
        return m_name;
    }
    int Player::getHP()const
    {
        return m_hp;
    }
    int Player::getCoins()const
    {
        return m_coins;
    }

void Player::decreaseForce() {
    m_force--;
    if(m_force<=0)
    {
        m_force=0;
    }
}

       
  


 

















