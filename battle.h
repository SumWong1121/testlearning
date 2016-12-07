#ifndef battle_h
#define battle_h
#include <iostream>
#include "Enemy.h"
#include "playerstat.h"
#include "Skill.h"
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
class battle
{
public:
    unsigned int seed = time(0);
    playerstat me;
    Enemy you;
    skill image;
    bool dead = false, run = false, phy = false, mag = false, heal = false, def = false;
    int damage = 0, usedskill = 0;
    bool miss = false, dodge = false, movement = false, crit = false;
    bool playerstart = false;
    int tempPdef = 0, tempEdef = 0;
    int counter = 0;
    void battleSequence()
    {
        me.load();
        srand(seed);
        displaymetenemy();
        you.EnemyMaxHealth = (rand()% you.EnemyMaxHealth + you.EnemyHealth);
        you.EnemyHealth = you.EnemyMaxHealth;
        do
        {
            if(counter == 0)
            {
            if(rand()%100 > 50 )
            {
                displaybattlescene();
                execute_choice();
                if(run == false)
                    {   
                        image.getskilllook(phy, mag, def, heal, true);
                        calcalation(true);
                        displaybattlescene();
                        playerreset();
                        if(you.EnemyHealth > 0)
                        {calcalation(false);
                        image.getskilllook(you.physical, you.magical, you.defense, you.heal , false);
                        movement = true;
                        displaybattlescene();
                        enemyreset();
                        playerstart = true;}
                    }
            }
            else
            {
                displaybattlescene();
                calcalation(false);
                image.getskilllook(you.physical, you.magical, you.defense, you.heal, false);
                movement = true;
                displaybattlescene();
                enemyreset();
                if(me.currentHp  > 0)
                {execute_choice();
                if(run == false)
                    {   
                        image.getskilllook(phy, mag, def, heal, true);
                        calcalation(true);
                        displaybattlescene();
                        playerreset();
                    }
                }
            }
            }
            else if(playerstart == true)
            {
                displaybattlescene();
                execute_choice();
                if(run == false)
                    {   
                        image.getskilllook(phy, mag, def, heal, true);
                        calcalation(true);
                        displaybattlescene();
                        playerreset();
                        if(you.EnemyHealth > 0)
                        {calcalation(false);
                        image.getskilllook(you.physical, you.magical, you.defense, you.heal , false);
                        movement = true;
                        displaybattlescene();
                        enemyreset();
                        playerstart = true;}
                    }
            }
            else
            {
                displaybattlescene();
                calcalation(false);
                image.getskilllook(you.physical, you.magical, you.defense, you.heal, false);
                movement = true;
                displaybattlescene();
                enemyreset();
                if(me.currentHp > 0)
                {execute_choice();
                if(run == false)
                    {   
                        image.getskilllook(phy, mag, def, heal, true);
                        calcalation(true);
                        displaybattlescene();
                        playerreset();
                }}
            }
        //reset
        tempPdef = 0; 
        tempEdef = 0;
        miss = false;
        dodge = false;
        usedskill = 0;
        counter++;
        }while(me.Hp > 0 && you.EnemyHealth > 0 && run == false);
        if(me.Hp < 0)
        {
            displaydead();
            dead = true;
        }
        else if(run == true)
            displayrun();
        else
            displayendscene();
        me.calculation();
        run = false;
        counter = 0;
        playerstart = false;
        me.save();
    }//enemy met

    void execute_choice() //execute skill/attack choice
    {
        int choice = 0;
        cout << "--------------------------------------------------" << endl;
        cout << "\nAttack Menu\n___________________________________________\n";
	    cout << left << setw(25) << "1. Attack" << setw(20) << "2. Magic" << endl;
	    cout << left << setw(25) << "3. Run Away" << setw(20) << "4.Defense" << endl;
	    if(me.Mp > 9)
        {
        while(choice> 4 || choice < 1)
                {
                cout << "\n\nEnter the number of your attack:" << endl;
	            if(!(cin >> choice))
                {cout << "you must input numbers!\n";cin.clear();cin.ignore(10000,'\n');}
                if(choice>4 || choice < 1)
                    cout << "Invalid Input!\n";
                }
        }
        else
        {
            while(choice!= 4 && choice != 1 && choice !=3)
                {
                cout << "\nNoted:Not Enough mana to cast magic!\nEnter the number of your attack:" << endl;
	            if(!(cin >> choice))
                {cout << "you must input numbers!\n";cin.clear();cin.ignore(10000,'\n');}
                if(choice>4 || choice < 1)
                    cout << "Invalid Input!\n";
                else if(choice == 2)
                    cout << "Not enough Mp!!!!!!!\n";
                }
        }
        switch(choice)
        {
        case 1: phy = true;
                usedskill = choice;
                break;
        case 2: cout << "\nMagic Menu\n___________________________________________\n";
	            cout << left << setw(25) << "5. Lightning Bolt 9 MP" << setw(20) << "6. Cure   12 MP" << endl;
	            cout << left << setw(25) << "7. Holy          15 MP" << setw(20) << "8. Meteor 20 MP" << endl;
	            do
                {
                cout << "\n\nEnter the number of your spell:" << endl;
	            if(!(cin >> choice))
                {cout << "you must input numbers!\n";cin.clear();cin.ignore(10000,'\n');}
                if(choice>8 || choice < 5 )
                    cout << "Invalid Input!\n";
                else if(me.Mp < enoughMp(choice))
                    cout << "Not Enough Mp!\n";
                }while(choice > 8 || choice < 5 || me.Mp < enoughMp(choice));
                usedskill = choice;
                if(usedskill == 6)
                    heal = true;
                else
                    mag = true;
                break;
        case 3:if((rand() % 100 )> 50)
                    run = true;
               else
                    cout << "\n You failed to run away!!\n";
                Sleep(2000);
               break;
        case 4: def = true;
                break;
        }
        choice = 0;
    }
    void displaymetenemy() //display what enemy we met
    {
        system("cls");
        cout << "-------------------------\n";
        cout << "      enemy is here!     \n";
        cout << "     ready to battle!    \n";
        cout << "-------------------------\n";
        system("pause");    
    }
    void displaybattlescene() //display the action
    {
        system("cls");
        cout << right << setw(11) << "Your Hp" << setw(36) << "Enemy Hp" << endl;
        cout << right << setw(7) << me.currentHp << "/" << left << setw(7) << me.Hp;
        cout << right << setw(27) << you.EnemyHealth << "/" << left << setw(7) << you.EnemyMaxHealth << endl;
        if(phy == true || mag == true || def == true || you.physical == true || you.magical == true || you.defense == true)
        {
            for(unsigned int c = 0; c < 10; c++)
            {
            cout << me.avatar[c] << image.direction[c] << image.look[c] << image.direction[c] << you.avater[c] << endl;
            }
        }
        else if(heal == true)
        {   
            for(unsigned int c = 0; c < 10; c++)
            {
            cout << me.avatar[c] << image.direction[c] << image.look[c] << "     " << you.avater[c] << endl;
            }
        }
        else if(you.heal == true)
        {   
            for(unsigned int c = 0; c < 10; c++)
            {
            cout << me.avatar[c] << "     " << image.look[c] << image.direction[c] << you.avater[c] << endl;
            }
        }
        else
        {
            for(unsigned int c = 0; c < 10; c++)
            {
            cout << me.avatar[c] << "                    " << you.avater[c] << endl;
            }
        }
        if(movement == true)
        {
            cout << "--------------------------------------------------\n";
            cout << "result____________________________________________\n";
            if(miss == true)
                cout << "Opssssssss!You missed!!!!!~\n";
            else if(dodge == true)
                cout << "Woah! You dodged!\n";
            else
            {
                if(heal == true)
                    cout << "You heal yourself for " << damage << "Hp!\n";
                else if(you.heal == true)
                    cout << you.EnemyName << " heal himself for " << damage << "Hp!\n";
                else if(def == true || you.defense == true)
                    cout << "Defense going up!\n";
                else if(phy == true || mag == true)
                    cout << "You did " << damage << " damage to " << you.EnemyName << " !\n";
                else
                    cout << you.EnemyName << " did " << damage << " damage to you!\n";
                if(crit == true)
                    cout << "It's a critical hit!\n";
            }
            Sleep(2000);
        }

    }
    void calcalation(bool playermove) //the damage deal and reduce of hp calcalation
    {
        if(playermove == true)
        {
            if(rand()% 100 > me.Accurate && heal != true)
                miss = true;
            if(rand()% 100 > me.Crit)
                crit = true;
            if(run == false && miss == false) 
            {
                switch(usedskill)
                    {
                        case 1: if(tempEdef != 0)
                                    {damage = me.Patt - tempEdef;}
                                else
                                    damage = me.Patt - you.EnDef;
                                if(damage < 0)
                                    damage = 0;
                                if(crit = true)
                                    damage *= 2;
                                you.EnemyHealth -= damage;
                                break;
                        case 4:tempPdef = me.Pdef * 0.75 + me.Mdef * 0.75;
                                break;
                        case 5:damage = (rand()% me.Matt)*1.5;
                            if(tempEdef != 0)
                                    {damage -= tempEdef;}
                                else
                                    damage -= you.EnDef;    
                            if(damage < 0)
                                    damage = 0;
                            if(crit = true)
                                    damage *= 2;
                                you.EnemyHealth -= damage;
                               me.Mp -=9;break;
                        case 6:damage = rand() % me.Matt + 10;
                                me.currentHp += damage;
                                if(me.currentHp > me.Hp)
                                    me.currentHp = me.Hp;
                               me.Mp -=12;break;
                        case 7:damage = rand() % me.Matt + (me.Patt * 0.1);
                                if(tempEdef != 0)
                                    {damage -= tempEdef;}
                                else
                                    damage -= you.EnDef;
                                if(damage < 0)
                                    damage = 0;
                                if(crit = true)
                                    damage *= 2;
                                you.EnemyHealth -= damage;
                                me.Mp -=15;break;
                        case 8:damage = rand() % me.Matt + me.Matt * 0.9;
                                if(tempEdef != 0)
                                    {damage -= tempEdef;}
                                else
                                    damage -= you.EnDef;
                               if(damage < 0)
                                    damage = 0;
                               if(crit = true)
                                    damage *= 2;
                                you.EnemyHealth -= damage;
                                me.Mp -=20;break;
                    }
            }
        }
        else
        {    
            if(rand()%100 < me.Evasion && you.heal != true)
                dodge = true;
            if(dodge == false)
            {
                    damage = you.CDRM();
                    if(you.defense != true)
                    {
                        if(you.heal == true)
                        {you.EnemyHealth += damage;
                        if(you.EnemyHealth > you.EnemyMaxHealth)
                        you.EnemyHealth = you.EnemyMaxHealth;}
                        else if(you.physical == true && tempPdef == 0)
                            damage-= me.Pdef;
                        else if(you.magical == true && tempPdef == 0)
                            damage-=me.Mdef;
                        else 
                            damage-= tempPdef;

                        if(damage < 0)
                            damage = 0;
                        if(you.heal != true)
                        me.currentHp -= damage;
                    }
                    else
                        damage = tempEdef; 
            }
        }
        movement = true;
    }
    void displayendscene() //display endbattle scene
    {
        system("cls");
        cout << "-------------------------\n";
        cout << "      You killed it!     \n";
        cout << "  You earned some money! \n";
        cout << "         Gold + " << you.Gold << endl;
        cout << "-------------------------\n";
        me.gold += you.Gold;
        me.Level += 1;
        me.maxstatpoint += 1;
        me.Mp = me.MaxMp;
        me.currentHp = me.Hp;
        me.escape = false;
        system("pause");
    }
    void displaydead() //display dead scene
    {
        system("cls");
        cout << "-------------------------\n";
        cout << "      You Are Dead!      \n";
        cout << "    Please try again!    \n";
        cout << "-------------------------\n";
        cout << "return to main menu~...\n";
        system("pause");
    }
    void displayrun()
    {
        system("cls");
        cout << "-------------------------\n";
        cout << "      You Ran Away!      \n";
        cout << "-------------------------\n";
        me.escape = true;
        system("pause");
    }
    int enoughMp(int choice)
    {
        int number = 0;
        switch(choice)
        {case 5:number = 9;
        case 6:number = 12;
        case 7:number = 15;
        case 8:number = 20;
        }
        return number;
    }
    void playerreset()
    {
    movement = false;
    heal = false;
    def = false;
    phy = false;
    mag = false;
    miss = false;
    dodge = false;
    crit = false;
    }
    void enemyreset()
    {
    movement = false;
    you.physical = false;
    you.magical = false;
    you.defense = false;
    you.heal = false;
    miss = false;
    dodge = false;
    crit = false;
    }
};
#endif