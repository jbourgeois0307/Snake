#include "Game.h"
Game::Game() :slow_m{ 500 },reader_m{nullptr}
{

}


Game::~Game()
{
}
Game::State Game::nextState(State state)
{

	return (State)((int) state + 1);
}

void Game::gameLoop(State state) {
	
	timer.start();
	double lastTime = timer.elapsed();
	while (true)
	{
		double current = timer.elapsed();
		
		//double elapsed = current - lastTime;
		processInput();
		update(state);
		render();
		lastTime = current;
	}
}
void Game::processInput() {
	//(*reader_m).read(keyEvents);
}
void Game::render() {

}
Game::State Game::update(State state) {
	//FAIRE ENUM
	
	

	//for (int i{ 0 }; i < slow_m; i++) {
	//	for (int j{ 0 }; j < slow_m; j++) {
	//		for (int k{ 0 }; k< slow_m; k++);
	//	}
	//}
	switch (state) {
	case State::Welcome: if (GameArea::getInstance().welcomeMenu(keyEvents)) {
		return nextState(state);
	}
			else {
		return state;
	}
			break;
	case State::StartMenu: if (GameArea::getInstance().newGameMenu(keyEvents)) {
		return nextState(state);
	}
			else {
				return state;
	}
			break;
	case State::GameModeChooser: if (GameArea::getInstance().gameModeChooser(keyEvents)) {
			return nextState(state);
	}
			else {
			return state;
	}
			break;
	case State::Options: if (GameArea::getInstance().optionMenu(keyEvents)) {
			return nextState(state);
	}
			else {
			return state;
	}
			break;
	case State::SinglePlayer: GameSinglePlayer::getInstance();
		if (GameSinglePlayer::getInstance().play(keyEvents)) {
			return nextState(state);
	}
			else {
return state;
	}
			break;
	case State::Multiplayer: if (GameArea::getInstance().multiplayer(keyEvents)) {
  gameLoop(nextState(state));
	}
			else {
return state;
	}
			break;
	case State::Plateformer: if (GameArea::getInstance().plateformer(keyEvents)) {
  gameLoop(nextState(state));
	}
			else {
return state;
	}
			break;
	case State::GameOver: if (GameArea::getInstance().gameOverMenu(keyEvents)) {
  gameLoop(nextState(state));
	}
			else {
return state;
	}
			break;
	}
}

void Game::start(size_t width, size_t height) {
	
	ConsoleContext context(2000, 2000, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);

	Game::getInstance().gameLoop(State::SinglePlayer);
}

