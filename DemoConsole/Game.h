#ifndef GAME_H
#define GAME_H

#include "Console.h"


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
	void generateGameArea();
	void generateSnake();
	void generateApple();
};

#endif