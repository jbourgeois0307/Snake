#ifndef MULTI_H
#define MULTI_H
#include "GameSinglePlayer.h"
#include "Snake.h"
class GameMultiPlayer : public GameSinglePlayer
{
private:
	GameMultiPlayer();
	GameMultiPlayer(Point p);
	~GameMultiPlayer();
public:
	static GameMultiPlayer& getInstance()
	{
		static GameMultiPlayer instance;
		return instance;
	}

	void generateSnake();

	void showSnake(ConsoleImage & image);

private:

	Snake adversary_m;
};

#endif