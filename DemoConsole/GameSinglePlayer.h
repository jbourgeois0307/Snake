#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include "Console.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"
#include "Snake.h"
#include "FruitFactory.h"

class GameSinglePlayer
{
protected:
	GameSinglePlayer();
	~GameSinglePlayer();

	bool haveFruit_m;
	bool snakeExist_m;
	Fruit *fruit_m;
	Snake *snake_m;
	

public:
	static GameSinglePlayer& getInstance()
	{
		static GameSinglePlayer instance;
		return instance;
	}

	bool play();
	//void generateFruit();
	void generateFruit();
	void generateSnake();
	void showSnake(ConsoleImage & image);
	void showFruit(ConsoleImage & image);
	void slitherSnake();
	void directionSnake(Snake::Direction direction);
	Snake::Direction& curDirection();
	Snake* snake();
	Fruit* fruit();

};

#endif //SINGLEPLAYER_H