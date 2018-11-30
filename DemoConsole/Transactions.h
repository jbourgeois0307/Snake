#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Snake.h"
#include "Game.h"
#include "SinglePlayerAutomaton.h"
class Transaction
{
private:
	Transaction();
	~Transaction();
public:
	static Transaction& getInstance()
	{
		static Transaction instance;
		return instance;
	}
	bool conditionStartMenu();
	bool conditionGameModeChooser();
	bool conditionOptions();
	bool conditionWelcome();
	bool conditionSinglePlayer();
	bool conditionMultiPlayer();
	bool conditionPlatformer();
	bool conditionGameOver(Snake snake);
};
#endif //TRANSACTIONS_H