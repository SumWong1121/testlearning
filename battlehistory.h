#ifndef BATTLE_HISTORY_H
#def BATTLE_HISTORY_H

//create a list of the reward that the player get from the battles
//make sure that player can know which battle got what

//and design a battle history page to let player to check the records
//enemy name get from battle.h(you.EnemyName)
//enemy gold get from battle.h(you.Gold)

#include <cstdlib>
#include "battle.h"
#include <string>
#include <fstream>

class battle_history
{
	private:
		std::size_t battle_count;
		int collected_gold;
		string name;
	public:
		battle_history();
		void record();
		void retreive(char command);

};




#endif
