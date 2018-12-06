#ifndef GAMEAREA_H
#define GAMEAREA_H

#include "Console.h"
#include "Fruit.h"
class GameArea
{
private:
	GameArea();
	~GameArea();
	int mGameScore;

public:

	static GameArea& getInstance()
	{
		static GameArea instance;
		return instance;
	}

	bool singleplayer();
	bool multiplayer();
	bool plateformer();
	bool welcomeMenu();
	bool optionMenu();
	bool gameModeChooser(int pos);
	bool gameOverMenu();

	bool newGameMenu(std::string name);


};

#endif