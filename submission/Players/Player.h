#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
int const MAX_HP=100;
int const START_COINS=10;
int const START_FORCE=5;
int const START_LEVEL=1;
class Player
{
    protected:
        std::string m_name;
        int m_maxhp;
        int m_force;
        int m_hp;
        int m_level;
        int m_coins;
        public:
             std::string getName()const;
             virtual std::string getJob()const=0;
            int getHP()const;
            int getCoins()const;
            Player(std::string name);
            Player( const Player& other)=default;
           virtual ~Player()=default;
            Player& operator=(const Player& other)=default;
            friend std::ostream& operator<<(std::ostream& os, const Player &player);
            Player& levelUp();
            int getLevel()const;
            Player& buff( const int force); 
           virtual Player& heal( const int hp);
            Player& damage(const int damage);
            bool isKnockedOut() const;
           virtual Player& addCoins( const int coins);
            virtual int getAttackStrength()const;
             bool pay( const int pay);
             void decreaseForce();
};
#endif
