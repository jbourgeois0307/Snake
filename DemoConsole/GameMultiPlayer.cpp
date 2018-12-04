#include "GameMultiPlayer.h"
#include <vector>

GameMultiPlayer::GameMultiPlayer() :haveFruit_m{ false }, snakeExist_m{ false }, fruit_m{ Fruit(Point(5, 5), 5) }, snake_m{ Snake(0.5f) }
{

}
GameMultiPlayer::~GameMultiPlayer()
{
}

bool GameMultiPlayer::play()
{
	if (!haveFruit_m) {
		getInstance().generateFruit();
	}

	return false;
}
void GameMultiPlayer::generateFruit() {
	if (!haveFruit_m) {
		Point p(Random::getInstance().uniformRandomize(1, 89) + 5, Random::getInstance().uniformRandomize(1, 89) + 5);
		fruit_m.setPoint(p);
		haveFruit_m = true;
	}

}
void GameMultiPlayer::generateFruit(bool newFruit) {
	if (newFruit) {
		Point p(Random::getInstance().uniformRandomize(1, 89) + 5, Random::getInstance().uniformRandomize(1, 89) + 5);
		fruit_m.setPoint(p);
		haveFruit_m = true;
	}

}


void GameMultiPlayer::generateSnake()
{
	if (!snakeExist_m) {
		Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
		snake_m = Snake(0.5f, p);

		Point p2(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
		caterpillar_m = Snake(0.5f, p2);

		GameMultiPlayer::snakeExist_m = true;
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
		std::vector<Point>caterpillarPart{ caterpillar_m.bodPart() };
		for (int i{ 0 }; i < caterpillar_m.bodLength() - 1; ++i) {
			image.drawPoint(caterpillar_m.bodPart().at(i).x(), caterpillar_m.bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::tb);
		}
	}

}

void GameMultiPlayer::showFruit(ConsoleImage & image)
{
	if (haveFruit_m) {
		image.drawPoint(fruit_m.point().x(), fruit_m.point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}

void GameMultiPlayer::slitherSnake()
{
	snake_m.slither();
}
void GameMultiPlayer::slitherCaterpillar()
{
	caterpillar_m.slither();
}

void GameMultiPlayer::directionSnake(Snake::Direction direction)
{
	snake_m.setCurDirection(direction);
}
void GameMultiPlayer::directionCaterpillar(Snake::Direction direction)
{
	caterpillar_m.setCurDirection(direction);
}

Snake::Direction & GameMultiPlayer::curDirection()
{
	//Change la direction courante du snake
	return snake_m.curDirection();
}

Snake::Direction & GameMultiPlayer::curDirectionCaterpillar()
{
	//Change la direction courante du snake
	return caterpillar_m.curDirection();
}

Snake& GameMultiPlayer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Snake& GameMultiPlayer::caterpillar()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return caterpillar_m;
}

Fruit GameMultiPlayer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
