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

	void singleplayer();
	void multiplayer();
	void plateformer();
	void welcomeMenu();
	void newGameMenu();
	void optionMenu();
	void gameModeChooser();
	void gameOverMenu();
};

