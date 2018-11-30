#include "GameMultiPlayer.h"


GameMultiPlayer::GameMultiPlayer()
{
	GameMultiPlayer::GameMultiPlayer(Point(10, 10));
}

GameMultiPlayer::GameMultiPlayer(Point p ) : adversary_m{Snake(0.5f,p)}
{
}


GameMultiPlayer::~GameMultiPlayer()
{
}

void GameMultiPlayer::generateSnake() {
	if (!GameSinglePlayer::snakeExist_m) {
		GameSinglePlayer::getInstance().generateSnake();
		Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
		adversary_m = Snake(0.5f, p);
		GameSinglePlayer::snakeExist_m = true;
	}
}

void GameMultiPlayer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake_m.bodPart() };
		for (int i{ 0 }; i < snake_m.bodLength() - 1; ++i) {
			image.drawPoint(snake_m.bodPart().at(i).x(), snake_m.bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}

		std::vector<Point>adversyPart{ adversary_m.bodPart() };
		for (int i{ 0 }; i < adversary_m.bodLength() - 1; ++i) {
			image.drawPoint(adversary_m.bodPart().at(i).x(), adversary_m.bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::tb);
		}
	}
}