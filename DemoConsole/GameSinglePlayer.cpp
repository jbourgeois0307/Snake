#include "GameSinglePlayer.h"
#include "GreenFruit.h"
#include <vector>

GameSinglePlayer::GameSinglePlayer() :haveFruit_m{ false }, snakeExist_m{ false }, snake_m{ Snake(0.5f) }, fruit_m{nullptr}
{
	
}
GameSinglePlayer::~GameSinglePlayer()
{
	delete fruit_m;
}

bool GameSinglePlayer::play()
{
	if (!fruit_m) {
		getInstance().generateFruit();
	}
	
	return false;
}
//void GameSinglePlayer::generateFruit() {
//	if (!haveFruit_m) {
//		Point p(Random::getInstance().uniformRandomize(1, 90)+5, Random::getInstance().uniformRandomize(1, 90)+5);
//		fruit_m.setPoint(p);
//		haveFruit_m = true;
//	}
//	
//}
void GameSinglePlayer::generateFruit() 
{
		delete fruit_m;
		Point p(Random::getInstance().uniformRandomize(1, 90) + 5, Random::getInstance().uniformRandomize(1, 90) + 5);
		fruit_m = new GreenFruit(p, 5, 2.0);// (Point(5, 5), 5);
		haveFruit_m = true;
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
	if(fruit_m){
		image.drawPoint(fruit_m->point().x(), fruit_m->point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	}
}

void GameSinglePlayer::slitherSnake()
{
	snake_m.slither();
}

void GameSinglePlayer::directionSnake(Snake::Direction direction)
{
	snake_m.setCurDirection(direction);
}

Snake::Direction & GameSinglePlayer::curDirection()
{
	//Change la direction courante du snake
	return snake_m.curDirection();
}

Snake& GameSinglePlayer::snake()
{
	//getter du snake dans le jeu pour le test des conditions(transactions)
	return snake_m;
}

Fruit* GameSinglePlayer::fruit()
{
	//getter du fruit dans le jeu pour le test des conditions(transactions)
	return fruit_m;
}
