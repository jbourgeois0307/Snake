#ifndef GAMEAREA_H
#define GAMEAREA_H

#include "Console.h"
#include "Fruit.h"
class GameArea
{
private:
	GameArea();
	~GameArea();

public:

	static GameArea& getInstance()
	{
		static GameArea instance;
		return instance;
	}

	bool singleplayer();
	bool multiplayer(ConsoleKeyReader::KeyEvents& keyEvents);
	bool plateformer(ConsoleKeyReader::KeyEvents& keyEvents);
	bool welcomeMenu(ConsoleKeyReader::KeyEvents& keyEvents);
	bool newGameMenu(ConsoleKeyReader::KeyEvents& keyEvents);
	bool optionMenu(ConsoleKeyReader::KeyEvents& keyEvents);
	bool gameModeChooser(ConsoleKeyReader::KeyEvents& keyEvents);
	bool gameOverMenu(ConsoleKeyReader::KeyEvents& keyEvents);

	void showFruit(Fruit f);

};

#endif