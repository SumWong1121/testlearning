#ifndef Skill_h
#define Skill_h
#include <string>
#include <fstream>
using namespace std;
class skill
{
private:
    int Dposition[4];
    int Lposition[4];
    fstream SA;
    fstream SAI;
    fstream SD;
    fstream SDI;
public:
    string direction[10]={"     ",
                          "     ",
                          "     ",
                          "     ",
                          "     ",
                          "     ",
                          "     ",
                          "     ",
                          "     ",
                          "     "};
    string look[10]={"          ",
                     "          ",
                     "          ",
                     "          ",
                     "          ",
                     "          ",
                     "          ",
                     "          ",
                     "          ",
                     "          "};

    skill(){readindex();}
    void readindex()
    {      int position;
    SAI.open("skillAvatarindex.dat",ios::in|ios::binary);
    SDI.open("skilldirectionindex.dat",ios::in|ios::binary);
        for(unsigned int i = 0; i < 4; i++)
        {
            SAI >> position;
            Lposition[i] = position;
            SDI >> position;
            Dposition[i] = position;
        }
        SAI.close();
        SDI.close();
    }
    void getskilllook(bool physical, bool magical, bool defense, bool heal, bool playermove)
    {
       SD.open("skilldirection.dat",ios::in|ios::binary);
       SA.open("skillAvatar.dat",ios::in|ios::binary);
       if(playermove == true)
       {
            if(magical == true || defense == true || physical == true)
            {
               SD.seekg(Dposition[0],ios::beg);
             for(unsigned int i = 0;i < 10;i++)
             {getline(SD,direction[i],'\n');}
            }
            else if(heal == true)
            {
               SD.seekg(Dposition[1],ios::beg);
             for(unsigned int i = 0;i < 10;i++)
             {getline(SD,direction[i],'\n');}
            }
       }
       else
       {
            if(magical == true || defense == true || physical == true)
            {
             SD.seekg(Dposition[2],ios::beg);
             for(unsigned int i = 0;i < 10;i++)
             {getline(SD,direction[i],'\n');}
            }
            else if(heal == true)
            {
                SD.seekg(Dposition[3],ios::beg);
             for(unsigned int i = 0;i < 10;i++)
             {getline(SD,direction[i],'\n');} 
            }
       }
       if(magical == true)
       {
       SA.seekg(Lposition[1],ios::beg);
       for(unsigned int i = 0;i < 10;i++)
       {getline(SA,look[i],'\n');}
       }
       else if (physical == true)
       {
       SA.seekg(Lposition[0],ios::beg);
       for(unsigned int i = 0;i < 10;i++)
       {getline(SA,look[i],'\n');}
       }
       else if(defense == true)
       {
       SA.seekg(Lposition[2],ios::beg);
       for(unsigned int i = 0;i < 10;i++)
       {getline(SA,look[i],'\n');}
       }
       else if(heal == true)
        {
        SA.seekg(Lposition[3],ios::beg);
       for(unsigned int i = 0;i < 10;i++)
       {getline(SA,look[i],'\n');}
        }
        SD.close();
        SA.close();
    }
};
#endif
