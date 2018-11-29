#include "Game.h"
#include "Console.h"
#include "GameArea.h"

Game::Game()
{
	 

}


Game::~Game()
{
}
void Game::start(size_t width, size_t height) {
	
	typedef int position_t;
	
	ConsoleContext context(width, height, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);

	
	position_t randomX;
	position_t randomY;

	Fruit fruit();
}

void boucleDeJeu(int state) {
	
	switch (state) {
	case 1: GameArea::getInstance().welcome();
			break;
	}
}