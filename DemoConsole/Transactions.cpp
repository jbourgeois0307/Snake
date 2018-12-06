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


bool Transaction::conditionSnakeEat(Snake *snake, Fruit *fruit)
{
	//Si la tête est à la même position que le fruit
	if (snake != nullptr) {
		if (snake->bodPart().at(0).x() == fruit->point().x())
			if (snake->bodPart().at(0).y() == fruit->point().y()) {
				return true;
			}
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

		char keyEntered = toupper(k.keyA());
		if (keyEntered == 'W')
			return true;
		else if (keyEntered == 'A')
			return true;
		else if (keyEntered == 'S')
			return true;
		else if (keyEntered == 'D')
			return true;
	}
	return false;
}

bool Transaction::conditionAnyInput()
{
	if (Game::getInstance().getKeyEvents().size()>0)
	{
		Game::getInstance().getKeyEvents().clear();
		return true;
	}
	return false;
}

bool Transaction::conditionPause(std::list<ConsoleKeyEvent> ke)
{
	//Pause si le joueur clique sur "espace"
	for (auto &k : ke)
	{
		if (k.keyV() == VK_SPACE) {
			ke.clear();
			return true;
		}
	}
	return false;
}

bool Transaction::conditionSnakeCollision(Snake* snake) 
{
	if (snake != nullptr) {
		if (snake->checkCollisionHead() || snake->checkCollisionWall())
			return true;
	}
	return false;
}

bool Transaction::conditionSnakeCollision(Snake* snake, std::vector<Obstacle> &obstacles)
{
	if (snake != nullptr) {
		if (snake->checkCollisionHead() || snake->checkCollisionWall())
			return true;
		for (Obstacle o : obstacles) {
			for (int i = 0; i < o.Size(); i++) {
				Point p(o.X() + i, o.Y());
				if (snake->checkCollisionPoint(p)) {
					return true;
				}
			}
		}
	}

	return false;
}

bool Transaction::conditionSnakeCollision(Snake* snake, Snake* caterpillar)
{
	if (snake != nullptr) {
		if (snake->checkCollisionHead() || snake->checkCollisionWall() || snake->checkCollisionAdversary(caterpillar))
			return true;
		if (caterpillar->checkCollisionHead() || caterpillar->checkCollisionWall() || caterpillar->checkCollisionAdversary(snake))
			return true;
	}
	return false;
}


