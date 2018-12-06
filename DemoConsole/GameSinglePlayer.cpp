#include "GameSinglePlayer.h"
#include <vector>
#include "SinglePlayerAutomaton.h"

GameSinglePlayer::GameSinglePlayer() :haveFruit_m{ false }, snakeExist_m{ false }, snake_m{ nullptr }, fruit_m{nullptr}
{
}
GameSinglePlayer::~GameSinglePlayer()
{
	delete fruit_m;
	delete snake_m;
}

bool GameSinglePlayer::play()
{
	SinglePlayerAutomaton::getInstance().startSinglePlayerAutomaton();
	if (!fruit_m)
		generateFruit();
	if(!snake_m)
		generateSnake();
	
	return false;
}

void GameSinglePlayer::generateFruit() 
{
	delete fruit_m;
	FruitFactory f;
	fruit_m = f.createFruit();
	haveFruit_m = true;
}


void GameSinglePlayer::generateSnake()
{
	delete snake_m;
	Point p(Random::getInstance().uniformRandomize(1, 88) + 5, Random::getInstance().uniformRandomize(40, 88) + 5);
	snake_m = new Snake(0.5f, p);
	snakeExist_m = true;
}

void GameSinglePlayer::showSnake(ConsoleImage & image)
{
	if (snakeExist_m)
	{
		std::vector<Point>snakePart{ snake_m->bodPart() };
		for (int i{ 0 }; i < snake_m->bodLength()-1; ++i) {
			image.drawPoint(snake_m->bodPart().at(i).x(), snake_m->bodPart().at(i).y(), (char)178, ConsoleColor::bk + ConsoleColor::ty);
		}
	}
		
}

void GameSinglePlayer::showFruit(ConsoleImage & image)
{

	//Affiche selon la couleur du fruit
	if(fruit_m){
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

void GameSinglePlayer::slitherSnake()
{
	snake_m->slither();
}

void GameSinglePlayer::directionSnake(Snake::Direction direction)
{
	snake_m->setCurDirection(direction);
}

Snake::Direction & GameSinglePlayer::curDirection()
{
	//Change la direction courante du snake
	return snake_m->curDirection();
}

Snake* GameSinglePlayer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Fruit* GameSinglePlayer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
