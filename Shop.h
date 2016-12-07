#ifndef shop_h
#define shop_h
#include <iostream>
#include <string>
#include <iomanip>
#include "playerstat.h"
#include <windows.h>
using namespace std;
class shop
{
private:
	string gearname;
	int requiregold;
	int choice;
    playerstat playerinfo;
public:
	shop() : gearname("Weapon"), requiregold(0)
	{
        playerinfo.load();
		welcomemessage();
		while (choice != 5)
		{
		system("cls");
		displaygear();
		displaychoice();
		choice = getchoice();
		calculation();
		executebuying();
		}
		goodbyemessage();
        playerinfo.save();
	}
	void welcomemessage()
	{
		cout << "-----------------------------" << endl;
		cout << "welcome to the shop!         " << endl;
		cout << "-----------------------------" << endl;
		Sleep(2000);
		system("cls");
		return;
	}
	void thankyoumessage()
	{
		cout << "-----------------------------" << endl;
		cout << "Thank you for your spending! " << endl;
		cout << "-----------------------------" << endl;
		Sleep(2000);
		system("cls");
		return;
	}
	void goodbyemessage()
	{
		cout << "-----------------------------" << endl;
		cout << "Please come back soon!       " << endl;
		cout << "-----------------------------" << endl;
		Sleep(2000);
		system("cls");
		return;
	}
	void displaygear()
	{
		cout << "--------------------------------------------" << endl << endl;
		cout << "        ^         ___     _____        _    " << endl;
		cout << "       | |       /   |   |     |      | |   " << endl;
		cout << "       |W|      /-H- |   |  A  |      |S|   " << endl;
		cout << "      [===]    |* _ *|   | | | |     _|_|   " << endl;
		cout << "       |_|     |_|-|_|   |_| |_|    (___]   " << endl << endl;
		return;
	}
	void calculation()
	{
        requiregold = 0;
		if (choice > 0 && choice < 5)
		{
			if (playerinfo.Gearlevel[choice-1] == 0)
			{
				switch (choice)
				{
				case 1:requiregold = 10; break;
				case 2:requiregold = 5; break;
				case 3:requiregold = 15; break;
				case 4:requiregold = 5; break;
				}
			}
			else
			{
				switch (choice)
				{
				case 1: requiregold = 3 + static_cast <int>(playerinfo.Gearlevel[choice-1] * 1.25);
				case 2: requiregold = 5 + static_cast <int>(playerinfo.Gearlevel[choice-1] * 1.125);
				case 3: requiregold = 2 + static_cast <int>(playerinfo.Gearlevel[choice-1] * 1.5);
				case 4: requiregold = 5 + static_cast <int>(playerinfo.Gearlevel[choice-1] * 1.125);
				}
			}
		}
	return;
	}
	int getchoice()
	{
		int choice = 0;
		cout << "What is your choice?";
		while (choice < 1 || choice > 5)
		{
			if (!(cin >> choice))
				cout << "Invalid Input!Please input number only!" << endl;
			if (choice < 1 || choice > 5)
				cout << "Invalid Input!Please input 1-5 only!" << endl;
		}
	return choice;
	}
	void executebuying()
	{
		if (playerinfo.gold < requiregold)
        {cout << "You don't have enough gold to do it!" << endl;
        Sleep(2000);
		system("cls");}
		else
		{
			playerinfo.gold -= requiregold;
            playerinfo.Gearlevel[choice-1] +=1;
            if(choice != 5)
            {
                cout <<"\n Remaining Gold: " << playerinfo.gold << endl;
                switch (choice)
				{
                case 1: cout << "Sword Level: " << playerinfo.Gearlevel[choice-1] << endl;
				case 2: cout << "Head Level: " << playerinfo.Gearlevel[choice-1] << endl;
				case 3: cout << "Armor Level: " << playerinfo.Gearlevel[choice-1] << endl;
				case 4: cout << "Shoe Level: " << playerinfo.Gearlevel[choice-1] << endl;
				}
            }
			thankyoumessage();
		}
		return;
	}
	void displaychoice()
	{
		int digit;
		cout << "gold:";
		for(unsigned int i = 1;i < 5;i++)
		{requiregold = 0;
         choice=i;
		calculation();
		digit = checkdigit(requiregold);
        displaygold(digit);
        if(i == 4)
		cout << left << endl;
		else
		cout << left << "   ";
		}
		cout << "     ";

		for(unsigned int i=0;i < 4;i++)
		{if(playerinfo.Gearlevel[i] == 0 && i < 3)
			cout << right << setw(5) << "buy" << "     ";
		else if (playerinfo.Gearlevel[i] == 0 && i == 3)
			cout << right << setw(5) << "buy" << endl;
		else if (playerinfo.Gearlevel[i] >= 1 && i < 3)
			cout << right << setw(7) << "upgrade" << "   ";
		else if (playerinfo.Gearlevel[i] >= 1 && i == 3)
			cout << right << setw(7) << "upgrade" << endl;}
		cout << "--------------------------------------------" << endl;
		cout << "1.Weapon      2.Head       3.Armor" << endl;
		cout << "4.Shoe        5.Exit" << endl << endl;
		return;
	}
	int checkdigit(int gold)
	{
		int counter = 0;
		do
		{gold /= 10;
		counter++;}
        while(gold!=0);
		return counter;
	}
    void displaygold(int digit)
    {
        if(digit == 1)
		    cout << right << setw(4) << requiregold << "   " ;
		else if(digit == 2)
		    cout << right << setw(4) << requiregold << "   "; 
		else if(digit == 3)
		    cout << right << setw(5) << requiregold << "  " ;
		else if(digit == 4)
		    cout << right << setw(5) << requiregold << "  ";
		else if(digit == 5)
		    cout << right << setw(6) << requiregold << " " ;
		else if(digit == 6)
		    cout << right << setw(6) << requiregold << " " ;
		else if(digit == 7)
		    cout << right << setw(7) << requiregold; 
    return;
    }
};
#endif

