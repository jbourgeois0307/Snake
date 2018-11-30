#include "Game.h"

Game::Game() :slow_m{ 500 }, reader_m{ nullptr }, writer{ nullptr }, gamezone{nullptr}
{
}


Game::~Game()
{
}
Game::State Game::nextState(State state)
{
	return (State)((int)state + 1);
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
		render(state);
		lastTime = current;
	}
}
void Game::processInput() {
	//(*reader_m).read(keyEvents);
}
void Game::render(State state) {
	switch (state) {
	case State::Welcome: GameArea::getInstance().welcomeMenu();
		break;
	case State::StartMenu:GameArea::getInstance().newGameMenu();
		break;
	case State::GameModeChooser:GameArea::getInstance().gameModeChooser();
		break;
	case State::Options:GameArea::getInstance().optionMenu();
		break;
	case State::SinglePlayer:GameArea::getInstance().singleplayer();
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 1000; j++)
				for (int k = 0; k < 1000; k++);
		GameSinglePlayer::getInstance().showSnake();
		GameSinglePlayer::getInstance().showFruit();
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 1000; j++)
				for (int k = 0; k < 1000; k++);
		break;
	case State::Multiplayer:GameArea::getInstance().multiplayer();
		break;
	case State::Plateformer:GameArea::getInstance().plateformer();
		break;
	case State::GameOver:GameArea::getInstance().gameOverMenu();
		break;
	}
}
Game::State Game::update(State state) {
	switch (state) {
	case State::Welcome:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::StartMenu:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::GameModeChooser:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::Options:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::SinglePlayer:
		if (false) {
			return nextState(state);
		}
		else {
			GameSinglePlayer::getInstance().generateFruit();
			return State::GameOver;
		}
		break;
	case State::Multiplayer:
		if (true) {
			gameLoop(nextState(state));
		}
		else {
			return State::GameOver;
		}
		break;
	case State::Plateformer:
		if (true) {
			gameLoop(nextState(state));
		}
		else {
			return State::GameOver;
		}
		break;
	case State::GameOver:
		if (true) {
			gameLoop(nextState(state));
		}
		else {
			return State::StartMenu;
		}
		break;
	}
}

void Game::start(size_t width, size_t height) {

	ConsoleContext context(2000, 2000, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);

	ConsoleWriter & write{ Console::getInstance().writer() };

	Game::getInstance().gameLoop(State::SinglePlayer);
}

