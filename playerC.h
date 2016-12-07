#ifndef playerC_h
#define playerC_h
#include <iostream>
#include <string>
#include "playerstat.h"
#include "cstdlib"
#include "ctime"
using namespace std;
class playerC
{
private:
    playerstat me;
    string m_name;
    unsigned int m_hp, m_maxHp, m_mp, m_maxMp;
    unsigned int m_gold, m_yCoor = 0, m_xCoor = 0;
    char m_pic = '^';
public:
    //Constructors
    playerC(bool getsave)
    {
        if(getsave == true)
            me.load();
        else
            me.GenPlayerStat();

        setName(me.name);
        setHp(me.currentHp);
        setMaxHp(me.Hp);
        setMp(me.Mp);
        setMaxMp(me.MaxMp);
        setGold(me.gold);
        setPicture('^');
        me.save();
    }    
    //Functions
    void setName(string name){m_name = name;}
    void setHp(unsigned int hp){m_hp = hp;}
    void setMaxHp(unsigned int maxHp){m_maxHp = maxHp;}
    void setMp(unsigned int mp){m_mp = mp;}
    void setMaxMp(unsigned int maxMp){m_maxMp = maxMp;}
    void setGold(unsigned int gold){m_gold = gold;}
    void setYCoor(unsigned int yCoor){m_yCoor = yCoor;}
    void setXCoor(unsigned int xCoor){m_xCoor = xCoor;}
    void setPicture(char picture){m_pic = picture;}
    string getName(){ return m_name; }
    unsigned int getHp(){ return m_hp; }
    unsigned int getMaxHp(){ return m_maxHp;}
    unsigned int getMp(){ return m_mp;}
    unsigned int getMaxMp(){ return m_maxMp;} 
    unsigned int getGold(){ return m_gold; }
    unsigned int getYCoor( int number)
    {   
        if(m_yCoor == 0)
        {srand(time(0));m_yCoor = rand() % (number - 2) + 1;}
        return m_yCoor;
    }
    unsigned int getXCoor(int number)
    { 
        if(m_xCoor == 0)
        {srand(time(0));m_xCoor = rand() % (number - 2) + 1;}
        return m_xCoor;
    }
    char getPicture() { return m_pic;}
};
#endif