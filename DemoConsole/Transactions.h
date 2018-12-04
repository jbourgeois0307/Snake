#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Snake.h"
#include "Game.h"
#include "SinglePlayerAutomaton.h"
#include "Fruit.h"
#include "ConsoleKeyEvent.h"

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
	bool conditionSnakeCollision(Snake &snake);
	bool conditionMultiPlayer();
	bool conditionPlatformer();
	bool conditionGameOver(Snake snake);
	bool conditionSnakeMove(Snake snake);
	bool conditionSnakeEat(Snake snake, Fruit fruit);
	bool conditionMoveInput(std::list<ConsoleKeyEvent> ke);
};
#endif //TRANSACTIONS_H