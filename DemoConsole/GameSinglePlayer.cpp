#include "GameSinglePlayer.h"
#include <vector>

GameSinglePlayer::GameSinglePlayer() :haveFruit_m{ false }, snakeExist_m{ false }, fruit_m{ Fruit(Point(5, 5), 5) }, snake_m{ Snake(0.5f) }
{
	
}
GameSinglePlayer::~GameSinglePlayer()
{
}

bool GameSinglePlayer::play()
{
	if (!haveFruit_m) {
		getInstance().generateFruit();
	}
	
	return false;
}
void GameSinglePlayer::generateFruit() {
	if (!haveFruit_m) {
		Point p(Random::getInstance().uniformRandomize(1, 90)+5, Random::getInstance().uniformRandomize(1, 90)+5);
		fruit_m.setPoint(p);
		haveFruit_m = true;
	}
	
}

void GameSinglePlayer::generateSnake()
{
	if (!snakeExist_m) {
		Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
		snake_m = Snake(0.5f, p);
		GameSinglePlayer::snakeExist_m = true;
	}


}

void GameSinglePlayer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake_m.bodPart() };
		for (int i{ 0 }; i < snake_m.bodLength()-1; ++i) {
			image.drawPoint(snake_m.bodPart().at(i).x(), snake_m.bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}
	}
		
}

void GameSinglePlayer::showFruit(ConsoleImage & image)
{
	if(haveFruit_m){
		image.drawPoint(fruit_m.point().x(), fruit_m.point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}

Snake GameSinglePlayer::snake() const
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Fruit GameSinglePlayer::fruit() const
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
