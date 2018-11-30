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
	//Si la tête touche à la queue
	for (int i{ 1 }; i < snake.bodLength - 1; ++i) {
		if (snake.bodPart().at(0).x() == snake.bodPart().at(i).x())
			if (snake.bodPart().at(0).y() == snake.bodPart().at(i).y())
				//le Game over aura lieu
				return true;
	}
	//Sinon, continue la partie
	return false;
}
bool conditionMultiPlayer()
{
	return false;
}
bool conditionPlatformer()
{
	return false;
}