#include "GamePlateformer.h"
#include <vector>

GamePlateformer::GamePlateformer() :haveFruit_m{ false }, snakeExist_m{ false }, fruit_m{ Fruit(Point(5, 5), 5) }, snake_m{ Snake(0.5f) }
{

}
GamePlateformer::~GamePlateformer()
{
}

bool GamePlateformer::play()
{
	if (!haveFruit_m) {
		getInstance().generateFruit();
	}

	return false;
}
void GamePlateformer::generateFruit() {
	if (!haveFruit_m) {
		Point p(Random::getInstance().uniformRandomize(1, 89) + 5, 80);
		fruit_m.setPoint(p);
		haveFruit_m = true;
	}

}
void GamePlateformer::generateFruit(bool newFruit) {
	if (newFruit) {
		Point p(Random::getInstance().uniformRandomize(1, 89) + 5, 80);
		fruit_m.setPoint(p);
		haveFruit_m = true;
	}

}

void GamePlateformer::generateSnake()
{
	if (!snakeExist_m) {
		Point p(Random::getInstance().uniformRandomize(1, 90) + 5, 80);
		snake_m = Snake(0.5f, p);
		GamePlateformer::snakeExist_m = true;
	}
}

void GamePlateformer::generateObstacles()
{
	if (mNbFruit < 20) {
		for (int i = 0; i < 20; i++) {
			Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 80) + 5);
			size_t size = Random::getInstance().uniformRandomize(5, 10);
			mObstacles.push_back(Obstacle(size, p));
			GamePlateformer::snakeExist_m = true;
			++mNbFruit;
		}
	}
	
}

std::vector<Obstacle> & GamePlateformer::obstacles() {
	return mObstacles;
}

void GamePlateformer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake_m.bodPart() };
		for (int i{ 0 }; i < snake_m.bodLength() - 1; ++i) {
			image.drawPoint(snake_m.bodPart().at(i).x(), snake_m.bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}
	}

}

void GamePlateformer::showObstacles(ConsoleImage & image) {
		for (int i = 0; i < mNbFruit; ++i) {
				image.drawLine(mObstacles.at(i).X(), mObstacles.at(i).Y(), mObstacles.at(i).X()+mObstacles.at(i).Size(), mObstacles.at(i).Y(), (char)178, ConsoleColor::bg + ConsoleColor::ty);
		}
		
}

void GamePlateformer::showFruit(ConsoleImage & image)
{
	if (haveFruit_m) {
		image.drawPoint(fruit_m.point().x(), fruit_m.point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}

void GamePlateformer::slitherSnake()
{
	snake_m.slither();
}

void GamePlateformer::directionSnake(Snake::Direction direction)
{
	snake_m.setCurDirection(direction);
}

Snake::Direction & GamePlateformer::curDirection()
{
	//Change la direction courante du snake
	return snake_m.curDirection();
}

Snake& GamePlateformer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Fruit GamePlateformer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
