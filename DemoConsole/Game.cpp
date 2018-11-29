#include "Game.h"


Game::Game()
{

}


Game::~Game()
{
}

void Game::boucleDeJeu(int state) {
	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	switch (state) {
	case 1: if (GameArea::getInstance().welcomeMenu()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 2: if (GameArea::getInstance().newGameMenu()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 3: if (GameArea::getInstance().gameModeChooser()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 4: if (GameArea::getInstance().optionMenu()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 5: if (GameArea::getInstance().welcomeMenu()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 6: if (GameArea::getInstance().singleplayer()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 7: if (GameArea::getInstance().multiplayer()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 8: if (GameArea::getInstance().plateformer()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 9: if (GameArea::getInstance().gameOverMenu()) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	}
}

void Game::start(size_t width, size_t height) {
	
	typedef int position_t;
	
	ConsoleContext context(width, height, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);
	Game::getInstance().boucleDeJeu(6);
}

