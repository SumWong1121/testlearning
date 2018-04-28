#include "battlehistory.h"
#include "battle.h"
#include "playerstat.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;

/*battle_history::battle_history()
{
	number_pages = 0;
}*/

void battle_history::record(battle& player, playerstat& info)
{
	int battle_count = info.battlecount;
	int gold = player.you.Gold;
	string name = player.you.EnemyName;
	
	if(player.run == true)
	{
		print(battle_count,0, name, 1);
		return;
	}
	if(player.dead == true)
	{
		print(battle_count,0, name, 2);
		return;
		
	}
	
	print(battle_count,gold,name,0);

}

void battle_history::print(int count, int gold, string name, int special)
{
	fstream outFile;	
	string filename = "history";
	string postfix;
	
	postfix = get_postfix(count);
	filename.append(postfix);
	
	outFile.open(filename, ios::out | ios::binary);
	if(!outFile)
	{
			cout <<"Can't create file";
			return;
	}
		
	if(special == 2)
	{
		outFile <<"Battle " << count <<":" << endl;
		outFile <<setw(4)<<right << "You ran away from " << name<<"." << endl;
		outFile << endl;
		
		outFile.close();
		return;
	}
	else if(special == 3)
	{
		outFile <<"Battle " << count <<":" << endl;
		outFile <<setw(4)<<right << "You were defeated by " << name<<"." << endl;
		outFile << endl;
		
		outFile.close();
		return;
	}
	else if(special == 0)
	{
		
		outFile <<"Battle " << count <<":" << endl;
		outFile <<setw(8) << right << "Enemy: " << name << endl;
		outFile <<"The reward that you get: " << endl;
		outFile <<setw(2) << right<<gold << " Gold" <<endl;
		outFile << endl;
		outFile.close();
		return;
	}
	
}

string battle_history::get_postfix(int count, int page_in)
{
	string postfix;
	int page;
	if(count != -1)
	{
		if((count % 5) == 0)
		{
			page = count / 5;
			postfix = static_cast<ostringstream*>( &(ostringstream() << page) )->str(); //convert number to string;
			postfix.append(".txt");
			return postfix;
		}
		else
		{
			page = (count / 5) + 1;
			postfix = static_cast<ostringstream*>( &(ostringstream() << page) )->str(); //convert number to string;
			postfix.append(".txt");
			return postfix;
		}
	}
	else if (page_in != -1)
	{
		postfix = static_cast<ostringstream*>( &(ostringstream() << page_in) )->str();
		postfix.append(".txt");
		return postfix;
	}	
}

void battle_history::retreive(char command)
{
	fstream inFile;
	int current;
	char print;
	string filename = "history";
	string postfix;
	
	if(command == 'h' || command == 'H')
	{
		inFile("history1.txt", ios::in | ios::binary);
		
		if(!inFile)
		{
			cout << "The history is empty." << endl;
			return;
		}
		
		print = inFile.get()
		while(!inFile.eof())
		{
			cout << print;
			print = inFile.get();
		}
		current++;
		inFile.close();
		
	}
	else if(command == 'q' || command == "Q")
	{
		if(current == 1)
		{
		  cout << "There is no precedent history to display" << endl;
		  return;
		}
		else
		{
			current--;
			postfix = get_postfix(-1, count);
			filename.append(postfix);
			
			inFile(filename, ios::in | ios::binary);
			
			if(!inFile)
			{
				cout << "Can't open." << endl;
				return;
			}
			
			print = inFile.get()
			while(!inFile.eof())
			{
				cout << print;
				print = inFile.get();
			}
			inFile.close();
			
		}
	}
	else if(command == 'e' || command == "E")
	{
		if(current = //not yet done
	}
}
