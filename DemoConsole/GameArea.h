#pragma once
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
	bool multiplayer();
	bool plateformer();
	bool welcomeMenu();
	bool newGameMenu();
	bool optionMenu();
	bool gameModeChooser();
	bool gameOverMenu();
};
