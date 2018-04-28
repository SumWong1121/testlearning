#ifndef playerstat_h
#define playerstat_h
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
class playerstat
{
private:
    fstream PD;
    bool upgrade = false;
public:
    playerstat() {}
    string name = "";
    int  currentHp = 0;
    unsigned int Level = 0,
        maxstatpoint = 0,
        Hp = 0,
        Mp = 0,
        MaxMp = 0,
        Str = 0,
        Int = 0,
        Dex = 0,
        Luck = 0,
        Crit = 10,
        gold = 0,
        Bcount =0,
        Patt = 0,
        Matt = 0,
        Pdef = 0,
        Mdef = 0,
        Evasion = 20,
        Accurate = 40,
        seed = time(0),
        Gearlevel[4] = { 0, 0, 0, 0 };
    string avatar[10] = {"      ___      ",
                         "     /   \\     ",
                         "    C   | >  _ ",
                         "     \\___3  / |",
                         "     |  \\  / / ",
                         "     |  '\\/_/_ ",
                         "     |__|[=]_/ ",
                         "     |  |      ",
                         "     |  |      ",
                         "     |===>     "};
        bool escape = false;

    void GenPlayerStat()
    {
        srand(seed);
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "What is the name of your character?";
        getline(cin ,name);
        do
        {
        maxstatpoint = (rand() % 100 + 100);
        Level = 0;
        Str = (rand() % maxstatpoint);
        maxstatpoint -= Str;
        Int = (rand() % maxstatpoint);
        maxstatpoint -= Int;
        Dex = (rand() % maxstatpoint);
        maxstatpoint -= Dex;
        Luck = (rand() % maxstatpoint);
        maxstatpoint -= Luck;
        system("cls");
        cout << left << "Statpoint:" << right << setw(10) << maxstatpoint << endl;
        cout << left << "Str:" << right << setw(16) << Str << endl;
        cout << left << "Int:" << right << setw(16) << Int << endl;
        cout << left << "Dex:" << right << setw(16) << Dex << endl;
        cout << left << "Luck:" << right << setw(15) << Luck << endl;
         }while((GetYN("Do you want to reroll again?"))!='N');
        calculation();
        currentHp = Hp;
        Mp = MaxMp;
    }

    void calculation()
    {
        Hp = 100 + Str * 1.5 + Gearlevel[1] * 1 + Gearlevel[2] * 1.5;
        MaxMp = 50 + Int * 1.5 + Gearlevel[1] * 0.5 + Gearlevel[2] * 0.5;
        Patt = Str * 1.25 + Gearlevel[0] * 1.2;
        Matt = Int * 1.5 + Gearlevel[0] * 0.5;
        Pdef = Str * 1.1 + Gearlevel[1] * 0.75 + Gearlevel[2] * 1.25;
        Mdef = Int * 0.9 + Gearlevel[1] * 1.25 + Gearlevel[2] * 0.75;
        Evasion = 20 + Dex * 0.8 + Gearlevel[3] * 0.8;
        if (Evasion >= 80)
            Evasion = 80;
        Accurate = 40 + Dex * 0.6 + Gearlevel[0] * 0.3;
        if (Accurate >= 85)
            Accurate = 85;
        Crit = 10 + Luck * 0.5;
        if (Crit >= 70)
            Crit = 70;
        if(escape == false)
        {currentHp = Hp;Mp = MaxMp;}
    }

    void displayStat()
    {
        system("cls");
        calculation();
        char choice;
        cout << right << setw(15) << "PlayerStat" << endl;
        cout << left << "Level:" << right << setw(14) << Level << endl;
        cout << left << "Statpoint:" << right << setw(10) << maxstatpoint << endl;
        cout << left << "Hp:" << right << setw(17) << Hp << endl;
        cout << left << "MaxHp:" << right << setw(14) << currentHp << endl;
        cout << left << "Mp:" << right << setw(17) << Mp << endl;
        cout << left << "MaxMp:" << right << setw(14) << MaxMp << endl;
        cout << left << "Str:" << right << setw(16) << Str << endl;
        cout << left << "Int:" << right << setw(16) << Int << endl;
        cout << left << "Dex:" << right << setw(16) << Dex << endl;
        cout << left << "Luck:" << right << setw(15) << Luck << endl;
        cout << left << "Patt:" << right << setw(15) << Patt << endl;
        cout << left << "Matt:" << right << setw(15) << Matt << endl;
        cout << left << "Pdef:" << right << setw(15) << Pdef << endl;
        cout << left << "Mdef:" << right << setw(15) << Mdef << endl;
        cout << left << "Evasion:" << right << setw(12) << Evasion << endl;
        cout << left << "Accurate:" << right << setw(11) << Accurate << endl;
        cout << left << "Crit:" << right << setw(15) << Crit << endl;
        cout << left << "Gold:" << right << setw(15) << gold << endl;
        cout << left << "SwordLevel:" << right << setw(9) << Gearlevel[0] << endl;
        cout << left << "HeadLevel:" << right << setw(10) << Gearlevel[1] << endl;
        cout << left << "ArmorLevel:" << right << setw(9) << Gearlevel[2] << endl;
        cout << left << "ShoeLevel:" << right << setw(10) << Gearlevel[3] << endl;
        if (maxstatpoint > 0 && upgrade == false)
        {
            cout << "You can add " << maxstatpoint << " to one of the stat\n";
            choice = GetYN("Do you want to add it now?:"); 
            if (choice == 'Y')
                usestatpoint();
        }
        else
            system("pause");
        save();
    }

    char GetYN(string Prompt)
    {
        char yesno = ' ';
        cout << Prompt;
        while (yesno != 'Y' && yesno != 'N')
        {
            cin >> yesno;
            yesno = toupper(yesno);
            if (yesno != 'Y' && yesno != 'N')
            {cout << "Your Answer must be Y for yes or N for No!\n";
            cin.clear();
            cin.ignore(10000,'\0');}
        }
        return yesno;
        delete &yesno;
    }

    void usestatpoint()
    {
        int choice = 0, number = -1;
        while(maxstatpoint > 0 && choice != 5)
        {
        system("cls");
        cout << "choose one to upgrade from below\n";
        cout << left << "Str:" << right << setw(16) << Str << endl;
        cout << left << "Int:" << right << setw(16) << Int << endl;
        cout << left << "Dex:" << right << setw(16) << Dex << endl;
        cout << left << "Luck:" << right << setw(15) << Luck << endl;
        cout << "--------------------------------\n";
        cout << "1.Str    2.Int    3.Dex   4.Luck\n";
        cout << "choose from 1-5(5 = exit)";
        do
        {
            if(!(cin >> choice))
                {cout << "please only input 1-5!\n";cin.clear();cin.ignore(10000,'\0');}
            if(choice > 5 && choice < 1)
                cout << "You must choose from 1-5!\n";
        }while(choice > 5 && choice < 1);
        if(maxstatpoint > 1 && choice != 5)
        {
            do
            {cout << "how many stat point you want to put in it?(you have " << maxstatpoint << " point left): ";
            if(!(cin >> number))
            {cout << "please input numbers!\n";cin.clear();cin.ignore(10000,'\0');}
            if(number > maxstatpoint && number < 0)
            cout << "Invalid Input!\n";
            }
            while(number > maxstatpoint && number < 0);
        }
        else
            number = 1;
        if(choice != 5)
        {
            switch(choice)
            {
            case 1:Str += number;break;
            case 2:Int += number;break;
            case 3:Dex += number;break;
            case 4:Luck += number;break;
            }
            maxstatpoint -= number;
            number = -1;
            if(maxstatpoint == 0)
            upgrade = true;
            displayStat();
            upgrade = false;
        }
        else
            upgrade = true;
        save();
        }
    }
    /*void test()
    {
        GenPlayerStat();
        for(unsigned int i=0; i <10 ;i++)
        {cout << avatar[i] << endl;}
        system("pause");
        displayStat();
        maxstatpoint += 1;
        displayStat();
        displayStat();
    }*/
    void save()
    {
        PD.open("Playerdata.dat",ios::out|ios::binary);
        PD << name  << ":" << Str << " " << Int << " " << Dex << " " << Luck << " "
            << gold << " " << Gearlevel[0] << " " << Gearlevel[1] << " " << Gearlevel[2] << " " << Gearlevel[3];
        PD << " " << Level << " " << maxstatpoint << " " << Bcount;
        PD.close();
    }
    void load()
    {
        PD.open("Playerdata.dat",ios::in|ios::binary);
        getline(PD,name,':');
        PD >> Str >> Int >> Dex >> Luck >> gold
            >> Gearlevel[0] >> Gearlevel[1] >> Gearlevel[2] >> Gearlevel[3];
        PD >> Level >> maxstatpoint >> Bcount;
        PD.close();
        calculation();
    }
};
#endif
