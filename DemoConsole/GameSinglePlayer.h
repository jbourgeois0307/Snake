#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include "Console.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"

class GameSinglePlayer
{
private:
	GameSinglePlayer();
	~GameSinglePlayer();
	bool haveFruit_m;
	Fruit *fruit_m;
public:
	static GameSinglePlayer& getInstance()
	{
		static GameSinglePlayer instance;
		return instance;
	}

	bool play(ConsoleKeyReader::KeyEvents& keyEvents);
	void generateFruit();
	void generateSnake();
	void showSnake();
	void showFruit();

};

#endif