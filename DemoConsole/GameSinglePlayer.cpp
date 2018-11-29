#include "GameSinglePlayer.h"
#include "GameArea.h"
#include "Fruit.h"

GameSinglePlayer::GameSinglePlayer()
{
	Game::Game();
}


GameSinglePlayer::~GameSinglePlayer()
{
}

void Game::generateGameArea() {
	GameArea::getInstance().singleplayer();
}
void Game::generateApple() {
	Fruit fruit();
	
	fruit.getMY();
}
