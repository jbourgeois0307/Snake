#include "GameMultiPlayer.h"
#include "GreenFruit.h"
#include <vector>

GameMultiPlayer::GameMultiPlayer() :haveFruit_m{ false }, snakeExist_m{ false } , fruit_m{ nullptr }, snake_m{ nullptr }
{
}

GameMultiPlayer::~GameMultiPlayer()
{
	delete fruit_m;
}

bool GameMultiPlayer::play()
{
	if (!fruit_m) {
		generateFruit();
		generateSnake();
	}

	return false;
}
void GameMultiPlayer::generateFruit() 
{
	delete fruit_m;
	FruitFactory f;
	fruit_m = f.createFruit();
	haveFruit_m = true;
}


void GameMultiPlayer::generateSnake()
{
	delete snake_m;
	Point p(Random::getInstance().uniformRandomize(1, 49) + 5, Random::getInstance().uniformRandomize(40, 90) + 5);
	snake_m = new Snake(0.5f, p);

	Point p2(Random::getInstance().uniformRandomize(50, 90) + 5, Random::getInstance().uniformRandomize(40, 90) + 5);
	caterpillar_m = new Snake(0.5f, p2);
	snakeExist_m = true;

}

void GameMultiPlayer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake_m->bodPart() };
		for (int i{ 0 }; i < snake_m->bodLength() - 1; ++i) {
			image.drawPoint(snake_m->bodPart().at(i).x(), snake_m->bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}
		std::vector<Point>caterpillarPart{ caterpillar_m->bodPart() };
		for (int i{ 0 }; i < caterpillar_m->bodLength() - 1; ++i) {
			image.drawPoint(caterpillar_m->bodPart().at(i).x(), caterpillar_m->bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::tb);
		}
	}

}

void GameMultiPlayer::showFruit(ConsoleImage & image)
{
	if (fruit_m) {
		image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}

void GameMultiPlayer::slitherSnake()
{
	snake_m->slither();
}
void GameMultiPlayer::slitherCaterpillar()
{
	caterpillar_m->slither();
}

void GameMultiPlayer::directionSnake(Snake::Direction direction)
{
	snake_m->setCurDirection(direction);
}
void GameMultiPlayer::directionCaterpillar(Snake::Direction direction)
{
	caterpillar_m->setCurDirection(direction);
}

Snake::Direction & GameMultiPlayer::curDirection()
{
	//Change la direction courante du snake
	return snake_m->curDirection();
}

Snake::Direction & GameMultiPlayer::curDirectionCaterpillar()
{
	//Change la direction courante du snake
	return caterpillar_m->curDirection();
}

Snake* GameMultiPlayer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Snake* GameMultiPlayer::caterpillar()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return caterpillar_m;
}

Fruit* GameMultiPlayer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
