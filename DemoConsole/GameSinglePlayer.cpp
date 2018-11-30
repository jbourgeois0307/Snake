#include "GameSinglePlayer.h"


GameSinglePlayer::GameSinglePlayer() :haveFruit_m{ false }, fruit_m{ nullptr } {
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
	//Point p( Random::getInstance().bernoulliRandomize(90),Random::getInstance().bernoulliRandomize(90) );
	Point p(5, 5);
	fruit_m = &(Fruit(p, 1));
	haveFruit_m = true ;
}

void GameSinglePlayer::generateSnake()
{
}

void GameSinglePlayer::showSnake()
{
}

void GameSinglePlayer::showFruit()
{
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & fruitImage{ writer.createImage("fruit") };
	writer.push("fruit");
	Point p(5, 5);
	Fruit f(p, 1);
	fruitImage.drawLine(f.point().x(), f.point().y(), f.point().x(), f.point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
	fruitImage.drawLine(10.0,10.0, 10.0, 10.0, (char)178, ConsoleColor::bk + ConsoleColor::tr);

	//if(haveFruit_m)
	//	fruitImage.drawLine((*fruit_m).point().x(), (*fruit_m).point().y(), (*fruit_m).point().x(), (*fruit_m).point().y(), (char)178, ConsoleColor::bk + ConsoleColor::tr);
}
