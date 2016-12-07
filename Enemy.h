#ifndef Enemy_h
#define Enemy_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class Enemy
{
private:
    int EAposition[5];
    int EDposition[5];
    fstream EA;
    fstream EAI;
    fstream ED;
    fstream EDI;
public:
    unsigned int seed = time(0);
    string EnemyName;
	int EnemyHealth = 0;
	int EnemyMaxHealth = 0;
	int EnemyMP = 0;
	int EnAttDmg = 0;                                 //Enemy Attack Damage -- this varies from monster to monster
    int EnDef = 0;
	string BigAttk, LittAttk, Special, HealMove;   
    string avater[10]={"               ",
                       "               ",
                       "               ",
                       "               ",
                       "               ",
                       "               ",
                       "               ",
                       "               ",
                       "               ",
                       "               "};
    int Gold = 0;
    bool physical = false, magical = false, heal = false , defense = false;

    Enemy()
    {
        createdatabase();
        srand(seed);
        switch(gen_one())
        {
        case 0:getdata(EAposition[0],EDposition[0]);break;
        case 1:getdata(EAposition[1],EDposition[1]);break;
        case 2:getdata(EAposition[2],EDposition[2]);break;
        case 3:getdata(EAposition[3],EDposition[3]);break;
        case 4:getdata(EAposition[4],EDposition[4]);break;
        }
        gen_enemystat((rand() % 50));
    }

    void createdatabase()
    {
        int position;
        EAI.open("Enemyavatarindex.dat", ios::in|ios::binary);
        EDI.open("Enemydataindex.dat", ios::in|ios::binary);

        for(unsigned int i = 0;i < 5; i++)
        {
            EAI >> position;
            EAposition[i] = position;
            EDI >> position;
            EDposition[i] = position;
        }
        EAI.close();
        EDI.close();
    }
    bool gen_enemy()
    {
        bool yesno = false;
        if( (rand()%100) > (rand()%75) )
            yesno = true;
        return yesno;
    }

    int gen_one(){return (rand()%5);}

    void gen_enemystat(int playerlevel)
    {
        EnemyHealth += (playerlevel* 1.25 + (rand() % 10));
	    do
        {
        EnemyMaxHealth += (playerlevel* 1.5 + (rand() % 20));
        }while(EnemyMaxHealth < EnemyHealth);
	    EnemyMP += (playerlevel + (rand() % 25));
	    EnAttDmg += (playerlevel + (rand() % 25));
        EnDef += (playerlevel + (rand() % 25));
        Gold +=(playerlevel +(rand() % 25));
    }
    
    int CDRM()                      //calculate damage random movement
    {
        int number = 0, damage = 0;
        number = (rand()%100+1);
        if(number > 75)
            number = 4;
        else if (number > 50)
            number = 3;
        else if(number > 25)
            number = 2;
        else number = 1;

        switch(number)
        {
        case 1: damage = rand() % EnAttDmg + 5;
                if(EnemyName == "Slime")
                    magical = true;
                else
                    physical = true;
			    break;
        case 2: damage = rand() % (EnAttDmg + 30) + 11;
                if(EnemyName == "Stick Man" || EnemyName == "Minic")
                    magical = true;
                else
                    physical = true;
                break;
        case 3: damage = rand() % (EnAttDmg + 90) + 25;
                if(EnemyName == "Stick Man")
                    magical = true;
                else if(EnemyName == "Minic")
                        {defense = true;damage = EnDef * 1.5;}
                else
                    physical = true;
                break;
        case 4: damage = rand() % EnemyMaxHealth * 0.2;
                heal = true;
                break;
        }
        return damage;
    }

    void getdata(int Aposition, int Dposition)
    {
            EA.open("Enemyavatar.dat", ios::in|ios::binary);
            ED.open("Enemydata.dat", ios::in|ios::binary);
            ED.seekg(Dposition,ios::beg);
            getline(ED,EnemyName,':');
		    ED >> EnemyHealth >> EnemyMaxHealth >> EnemyMP;
		    getline(ED,BigAttk,';');
		    getline(ED,LittAttk,';');       
		    getline(ED,Special,';');       
		    ED >> EnAttDmg >> EnDef >> Gold;
            getline(ED,HealMove,'\n');
            EA.seekg(Aposition,ios::beg);
            for(unsigned int i=0; i < 10;i++)
            {getline(EA,avater[i],'\n');}
           EA.close();
           ED.close();          
    }
   /*void test()
   {
    for(unsigned int i=0; i <10 ;i++)
    {cout << avater[i] << endl;}
   cout << EnemyName << endl;
   cout << EnemyHealth << endl;
   cout << EnemyMaxHealth << endl;
   cout << BigAttk << endl;
   cout << LittAttk << endl;
   cout << Special << endl;
   cout << HealMove << endl;
   cout << EnAttDmg << endl;
   cout << EnDef << endl;
   cout << Gold << endl;
   }*/
   /*void outdata()
    {
        fstream a;
        fstream b;
        fstream c;
        fstream d;
        a.open("Enemyavatar.dat",ios::in|ios::out|ios::binary);
        b.open("Enemyavatarindex.dat",ios::in|ios::out|ios::binary);
        c.open("Enemydata.dat",ios::in|ios::out|ios::binary);
        d.open("Enemydataindex.dat",ios::in|ios::out|ios::binary);
        for(unsigned int k = 0;k<5;k++)
        {
            getdata(k);
            if(k!=4)
            b << a.tellg() << " ";
            else
                b << a.tellg();
            for(unsigned int i = 0; i < 10;i++)
            {
                a << avater[i] << endl;
            }

            if(k!=4)
            d << c.tellg() << " ";
            else
                d << c.tellg();
            c << EnemyName << ":" << EnemyHealth << " " << EnemyMaxHealth << " " << EnemyMP << " "
                << BigAttk << ";" << LittAttk << ";" << Special << ";"
                << EnAttDmg << " " << EnDef << " " << Gold << " " << HealMove << endl;
        }
    }*/
};
#endif