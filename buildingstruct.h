//structure header file for all the thing that can be display in the map
/*for now,we need:  forest
                    river
                    lake
                    tree
                    mountains
                    hill
                    doorway*/
//things need to be included in the structure:1.total size, 2.designed char for the print out
//declare a class to create a object for each of the structure(not print out)
//use coordinate system to design the map by using switch case
#ifndef BUILDINGSTRUCT_H
#def BUILDINGSTRUCT_H

#include <iostream>
#include <cstdlib>

struct symbol
{
	private:
		char tree = '$';
		char water = '~';
		char hill = '^';
		char bridge = '_';
    public:
		const char getchar(char input)
		{
			char b;
			switch (input)
			{
				case "T": 
					b = tree;
					break;
				case "W": 
					b = water; 
					break;
				case "H":
					b = water;
					break;
				case "B":
					b = bridge;
					break;
			}
			return b;
		}
};

struct forest
{	
	
	const std::size_t MAXIMUM = 100;
	const std::size_t MINIMUM = 10;
};

struct mountains
{
	const std::size_t MAXIMUM = 10;
	const std::size_t MINIMUM = 2;
};

struct river
{
	const std::size_t MAXIMUM = 150;
	const std::size_t MINIMUM = 30
};










