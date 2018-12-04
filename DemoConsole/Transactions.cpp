#include "Transactions.h"

Transaction::Transaction()
{
}

Transaction::~Transaction()
{
}
bool Transaction::conditionStartMenu()
{
	return false;
}
bool Transaction::conditionGameModeChooser()
{
	return false;
}
bool Transaction::conditionOptions()
{
	return false;
}
bool Transaction::conditionWelcome()
{
	return false;
}
bool Transaction::conditionSinglePlayer()
{
	SinglePlayerAutomaton::getInstance();
	return false;
}
bool Transaction::conditionMultiPlayer()
{
	return false;
}
bool Transaction::conditionPlatformer()
{
	return false;
}
bool Transaction::conditionGameOver(Snake snake)
{
	return false;
}
bool Transaction::conditionSnakeMove(Snake snake)
{
	return false;
}

bool Transaction::conditionSnakeEat(Snake snake, Fruit *fruit)
{
	//Si la tête est à la même position que le fruit
	if(snake.bodPart().at(0).x()==fruit->point().x())
		if (snake.bodPart().at(0).y() == fruit->point().y()) {
			return true;
		}
	return false;
}

bool Transaction::conditionMoveInput(std::list<ConsoleKeyEvent> ke)
{
	//Conditions pour autoriser un déplacement
	for (auto &k : ke)
	{
		if (k.keyV() == VK_UP)
			return true;
		else if (k.keyV() == VK_DOWN)
			return true;
		else if (k.keyV() == VK_LEFT)
			return true;
		else if (k.keyV() == VK_RIGHT)
			return true;
	}
	return false;
}

bool Transaction::conditionSnakeCollision(Snake& snake) 
{
	
	if (snake.checkCollisionHead() || snake.checkCollisionWall())
		return true;
	return false;
}


