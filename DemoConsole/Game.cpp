#include "Game.h"

Game::Game() :slow_m{ 500 }, reader_m{ Console::getInstance().keyReader() };
{

}


Game::~Game()
{
}
void Game::boucleDeJeu(int state) {

	reader_m.read(keyEvents);

	for (int i{ 0 }; i < slow_m; i++) {
		for (int j{ 0 }; j < slow_m; j++) {
			for (int k{ 0 }; k< slow_m; k++);
		}
	}
	switch (state) {
	case 1: if (GameArea::getInstance().welcomeMenu(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 2: if (GameArea::getInstance().newGameMenu(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 3: if (GameArea::getInstance().gameModeChooser(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 4: if (GameArea::getInstance().optionMenu(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 5: if (GameArea::getInstance().welcomeMenu(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 6: GameSinglePlayer::getInstance();
		if (GameSinglePlayer::getInstance().play(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 7: if (GameArea::getInstance().multiplayer(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 8: if (GameArea::getInstance().plateformer(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	case 9: if (GameArea::getInstance().gameOverMenu(keyEvents)) {
		boucleDeJeu(state + 1);
	}
			else {
		boucleDeJeu(state);
	}
			break;
	}
}

void Game::start(size_t width, size_t height) {
	ConsoleContext context(width, height, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);
	Game::getInstance().boucleDeJeu(7);
}

