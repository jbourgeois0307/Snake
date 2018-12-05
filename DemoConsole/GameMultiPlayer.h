#ifndef MULTI_H
#define MULTI_H

#include "Console.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"
#include "Snake.h"
#include "FruitFactory.h"
class GameMultiPlayer
{
protected:
	GameMultiPlayer();
	~GameMultiPlayer();

	bool haveFruit_m;
	bool snakeExist_m;
	Fruit *fruit_m;
	Snake *snake_m;
	Snake *caterpillar_m;


public:
	static GameMultiPlayer& getInstance()
	{
		static GameMultiPlayer instance;
		return instance;
	}

	bool play();
	void generateFruit();
	void generateSnake();
	void showSnake(ConsoleImage & image);
	void showFruit(ConsoleImage & image);
	void slitherSnake();
	void slitherCaterpillar();
	void directionSnake(Snake::Direction direction);
	void directionCaterpillar(Snake::Direction direction);
	Snake::Direction& curDirection();
	Snake::Direction & curDirectionCaterpillar();
	Snake* snake();
	Snake* caterpillar();
	Fruit* fruit();
};

#endif