#ifndef GAME_H
#define GAME_H

#include "Console.h"
#include "Fruit.h"
class GameArea
{
private:
	GameArea();
	~GameArea();

	ConsoleImage currentImage_m;
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
	bool newGameMenu();
	bool optionMenu();
	bool gameModeChooser();
	bool gameOverMenu();

	void showFruit(Fruit f) {

};

#endif