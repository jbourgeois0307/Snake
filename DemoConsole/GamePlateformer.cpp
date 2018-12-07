#include "GamePlateformer.h"
#include "GreenFruit.h"
#include <vector>
#include "PlateformerAutomaton.h"

GamePlateformer::GamePlateformer() :haveFruit_m{ false }, snakeExist_m{ false }, fruit_m{ nullptr }, snake_m{ nullptr }
{
}
GamePlateformer::~GamePlateformer()
{
	delete fruit_m;
	delete snake_m;
}

bool GamePlateformer::play()
{
	PlateformerAutomaton::getInstance().startPlateformerAutomaton();
	if (!fruit_m)
		generateFruit();
	if (!snake_m)
		generateSnake();

	return false;
}

void GamePlateformer::generateFruit() 
{
	delete fruit_m;
	FruitFactory f;
	fruit_m = f.createFruit();
	haveFruit_m = true;
}

void GamePlateformer::generateSnake()
{
	delete snake_m;
	Point p(Random::getInstance().uniformRandomize(1, 45) + 5, 80);
	snake_m = new Snake(0.5f, p);
	GamePlateformer::snakeExist_m = true;
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
		std::vector<Point>snakePart{ snake_m->bodPart() };
		for (int i{ 0 }; i < snake_m->bodLength() - 1; ++i) {
			image.drawPoint(snake_m->bodPart().at(i).x(), snake_m->bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
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

	//Affiche selon la couleur du fruit
	if (fruit_m) {
		if (fruit_m->color() == Fruit::FruitType::Red)
			image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
		if (fruit_m->color() == Fruit::FruitType::Green)
			image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tg);
		if (fruit_m->color() == Fruit::FruitType::Yellow)
			image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bw + ConsoleColor::ty);
		if (fruit_m->color() == Fruit::FruitType::Purple)
			image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tm);

	}
}

void GamePlateformer::slitherSnake()
{
	snake_m->slither();
}

void GamePlateformer::directionSnake(Snake::Direction direction)
{
	snake_m->setCurDirection(direction);
}

Snake::Direction & GamePlateformer::curDirection()
{
	//Change la direction courante du snake
	return snake_m->curDirection();
}

Snake* GamePlateformer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Fruit* GamePlateformer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}










