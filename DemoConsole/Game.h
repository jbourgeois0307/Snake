#ifndef GAME_H
#define GAME_H

#include "Console.h"
#include "GameSinglePlayer.h"
#include "GameArea.h"

class Game
{
private:
	Game();
	~Game();
public:
	void static start(size_t width=300, size_t height=800);

	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

private:
	void boucleDeJeu(int state = 1);
	size_t slow_m;
	ConsoleKeyReader & reader_m;
	ConsoleKeyReader::KeyEvents keyEvents;
};

#endif