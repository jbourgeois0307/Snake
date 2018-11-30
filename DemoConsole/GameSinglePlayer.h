#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include "Console.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"
#include "Snake.h"
class GameSinglePlayer
{
private:
	GameSinglePlayer();
	~GameSinglePlayer();

	bool haveFruit_m;
	bool snakeExist_m;
	Fruit fruit_m;
	Snake snake;
	

public:
	static GameSinglePlayer& getInstance()
	{
		static GameSinglePlayer instance;
		return instance;
	}

	bool play(ConsoleKeyReader::KeyEvents& keyEvents);
	void generateFruit();
	void generateSnake();
	void showSnake(ConsoleImage & image);
	void showFruit(ConsoleImage & image);

};

#endif