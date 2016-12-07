#ifndef ROOM_H_
#define ROOM_H_
#include <vector>
#include "playerstat.h"
#include <iomanip>
#include <iostream>
using namespace std;
class Room{
private:
    unsigned int m_yLength, m_xLength;
    const char m_floor = ' ', m_wall = '#';
    vector< vector<char> > m_room;
    playerstat me;
public:
    Room()
    {
        m_yLength = 3;
        m_xLength = 3;
        vector<vector <char> > tmp(m_yLength, vector<char>(m_xLength));
        m_room = tmp;
    }
    Room(int yLength, int xLength)
    {
        m_yLength = yLength;
        m_xLength = xLength;
        vector<vector <char> > tmp(yLength, vector<char>(xLength));
        m_room = tmp;
    }
    void displayRoom()
    {
        createPerimeter();
        for (unsigned int yCoor = 0; yCoor < m_yLength; yCoor++){
             for (unsigned int xCoor = 0; xCoor < m_xLength; xCoor++){
                    cout << m_room[yCoor][xCoor];}
        cout << endl;}
    }
    void setYLength(int yLength){m_yLength = yLength;}
    void setXLength(int xLength){m_xLength = xLength;}
    int getYLength(){ return m_yLength; };
    int getXLength(){ return m_xLength; }
    void createPerimeter(){me.load();
    for (unsigned int yCoor = 0; yCoor < m_yLength; yCoor++){
        for (unsigned int xCoor = 0; xCoor < m_xLength; xCoor++){
            if (xCoor == 0 || xCoor == m_xLength - 1 || yCoor == 0 || yCoor == m_yLength - 1)
            {m_room[yCoor][xCoor] = '#';}
            if (xCoor == (m_xLength-1))
            {
                if(yCoor == 0)
                    cout << right << setw(30) << "---The Infinite Dungeon---\n";
                if(yCoor == 5)
                    cout << right << setw(22) << "W  move up\n";
                if(yCoor == 8)
                    cout << right << setw(15) << "A move left" << right << setw(15) << "D move right\n";
                if(yCoor == 11)
                    cout << right << setw(22) << "S move down\n";
                if(yCoor == 13)
                    cout << right << setw(15) << "C character" << right << setw(10) << "Z Save\n";
                if(yCoor == 14)
                    cout << right << setw(15) << "Q Shop" << right << setw(10) << "E Exit\n";
            }
        }}}
    void enterObject(unsigned int yCoor, unsigned int xCoor, char picture){m_room[yCoor][xCoor] = picture;}
    void setblank(unsigned int yCoor, unsigned int xCoor){m_room[yCoor][xCoor] = m_floor;}
};
#endif


