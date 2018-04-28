#ifndef BATTLE_HISTORY_H
#def BATTLE_HISTORY_H

//create a list of the reward that the player get from the battles
//make sure that player can know which battle got what

//and design a battle history page to let player to check the records
//enemy name get from battle.h(you.EnemyName)
//enemy gold get from battle.h(you.Gold)


#include "battle.h"
#include "playerstat.h"
#include <string>
#include <fstream>

class battle_history
{
	//private:
		//int number_pages;
	public:
		//battle_history();
		void record(battle& player, playerstat& info);
		void retreive(char command);
		void print(int count, int gold, string name, int special = 0); //special: 0-win, 1-run, 2-dead
		//Print to file
		string get_postfix(int count = -1, int page_in = -1);
};
#endif
