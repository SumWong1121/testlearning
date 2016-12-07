#ifndef Game_h
#define Game_h
#include <iostream>
#include <string>
#include <cstdlib>
#include "playerC.h"
#include "Room.h"
#include "Enemy.h"
#include "playerstat.h"
#include "Shop.h"
#include "battle.h"
#include <windows.h>
using namespace std;
class Game
{
private:
    bool getsave = false;
    char playerMove = ' ';
public:    
    void run()
    {
        Room basement(15, 35);
        displaymenu();
        switch(execute_choice())
        {
        case 1:getsave = false;break;
        case 2:getsave = true;break;
        case 3:exit(0);break;
        }
        playerC ant(getsave);
        do{
        system("cls");
        basement.enterObject(ant.getYCoor(15), ant.getXCoor(35), ant.getPicture());
        basement.displayRoom();
        playerMove = getchoice(ant.getYCoor(15), ant.getXCoor(35));
                    switch (playerMove){
                    case 'Z': {playerstat me;me.save();cout << "Saved!\n";Sleep(2000);}break;
                    case 'E': break;
                    case 'Q': {shop a;}break;
                    case 'C': {playerstat me1;me1.load(); me1.displayStat();}break;
                    case 'W': {basement.setblank(ant.getYCoor(15), ant.getXCoor(35));ant.setYCoor(ant.getYCoor(15) - 1);} break;
                    case 'A': {basement.setblank(ant.getYCoor(15), ant.getXCoor(35));ant.setXCoor(ant.getXCoor(35) - 1);} break;
                    case 'D': {basement.setblank(ant.getYCoor(15), ant.getXCoor(35));ant.setXCoor(ant.getXCoor(35) + 1);} break;
                    case 'S': {basement.setblank(ant.getYCoor(15), ant.getXCoor(35));ant.setYCoor(ant.getYCoor(15) + 1);} break;
                    default:
                        break;
                    }
                    if(playerMove != 'E' && playerMove !='Z' && playerMove!='Q' && playerMove!='C')
                    {
                        Enemy b; 
                        if(b.gen_enemy()==true)
                        {
                            battle c;
                            c.battleSequence();
                        }
                    }
                    else if(playerMove == 'E')
                    {
                    cout << "Thz for playing!\n";
                    Sleep(2000);
                    }
        }while (playerMove !='E');
    }
    void displaymenu()
    {
    cout << "   THE                             \n";
    cout << "     Infinite                      \n";
    cout << "          Dungeon                  \n";
    cout << "       ____                        \n";
    cout << "      |Try |                       \n";
    cout << "      |To  |          1.New Start  \n";
    cout << "      |Find|          2.Load Saving\n";
    cout << "      |Your|          3.Exit       \n";
    cout << "      |Way |                       \n";
    cout << "      |Out |                       \n";
    cout << "      |____|                       \n";
    }
    int execute_choice()
    {
        int choice = 0;
        while(choice > 3 || choice < 1)
        {cout << "Please choose from 1-3: ";
        if(!(cin >> choice))
            {cout << "please input numbers!\n";cin.clear();cin.ignore(10000,'\n');}
            if(choice < 1 || choice > 3)
                cout << "Invalid Input!\n";}
        return choice;
    }
    char getchoice(unsigned int yCoor, unsigned int xCoor)
    {   
        bool wall = true;
        string nocheat;
        char choice ='x';
        while(choice !='E' && choice !='Q' && choice !='Z' && choice !='C' && choice !='W' && choice !='A' && choice !='S' && choice !='D' || wall != false)
        {wall = false;
        cout << "Plz enter your choice here:";
        cin >> nocheat;
        choice = toupper(nocheat[0]);
        if(choice !='E' && choice !='Q' && choice !='Z' && choice !='C' && choice !='W' && choice !='A' && choice !='S' && choice !='D')
            cout << "Invalid Input!\n";
        switch(choice)
        {
        case 'W':{if((yCoor - 1) > 0)
                        wall = false;
                 else
                 {wall = true;cout << "It's a wall!\n";}}
                 break;
        case 'A':{if((xCoor - 1) > 0)
                        wall = false;
                 else
                 {wall = true;cout << "It's a wall!\n";}}
                 break;
        case 'S':{if((yCoor + 1) < 14)
                        wall = false;
                 else
                 {wall = true;cout << "It's a wall!\n";}}
                 break;
        case 'D':{if((xCoor + 1) < 34)
                        wall = false;
                 else
                 {wall = true;cout << "It's a wall!\n";}}
                 break;
        case 'E':wall = false; break;
        case 'Z':wall = false; break;
        case 'Q':wall = false; break;
        case 'C':wall = false; break;
        }
        }
        return choice;
    }
};
#endif
