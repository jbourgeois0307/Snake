#include "GameSinglePlayer.h"
#include <vector>

GameSinglePlayer::GameSinglePlayer() :haveFruit_m{ false }, snakeExist_m{ true }, fruit_m{ Fruit(Point(5, 5), 5) }
{
	snake = Snake(0.5f);
}
GameSinglePlayer::~GameSinglePlayer()
{
}

bool GameSinglePlayer::play(ConsoleKeyReader::KeyEvents& keyEvents)
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
	Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
	snake = Snake(0.5, p );

}

void GameSinglePlayer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake.bodPart() };
		for (int i{ 0 }; i < snake.bodLength(); ++i) {
			image.drawPoint(snakePart.at(i).x(), snakePart.at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}
	}
		
}

void GameSinglePlayer::showFruit(ConsoleImage & image)
{
	if(haveFruit_m){
		image.drawPoint(fruit_m.point().x(), fruit_m.point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}
