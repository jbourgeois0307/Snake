#include "Game.h"
Game::Game() :slow_m{ 500 }, reader_m{ nullptr }, writer{ nullptr }, gamezone{ nullptr }
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

	//timer.start();
//	double lastTime = timer.elapsed();
	while (true)
	{
	//	double current = timer.elapsed();

//double elapsed = current - lastTime;
		processInput();
		update(state);
		render(state);
	//	lastTime = current;
	}
}
void Game::processInput() {
	(*reader_m).read(keyEvents);
}
void Game::render(State state) {
	switch (state) {
	case State::Welcome: GameArea::getInstance().welcomeMenu();
		break;
	case State::StartMenu:GameArea::getInstance().newGameMenu("hello");
		break;
	case State::GameModeChooser:GameArea::getInstance().gameModeChooser(positonChooser);
		break;
	case State::Options:GameArea::getInstance().optionMenu();
		break;
	case State::SinglePlayer:GameArea::getInstance().singleplayer();
		break;
	case State::Multiplayer:GameArea::getInstance().multiplayer();
		break;
	case State::Plateformer:GameArea::getInstance().plateformer();
		break;
	case State::GameOver:GameArea::getInstance().gameOverMenu();
		break;
	}
}
void Game::gamemodechooser(State& state){
	if (keyEvents.size() > 0) {
		for (auto &event : keyEvents) {
			if (event.keyA() == (int) '1')
			{
				positonChooser = 1;
			}
			if (event.keyA() == (int) '2')
			{
				positonChooser = 2;
			}
			if (event.keyA() == (int) '3')
			{
				positonChooser = 3;
			}
			int keyevent = event.keyA();
			if (event.keyA() == 13) {
				if (positonChooser == 1) {
					state = State::SinglePlayer;
				}
				if (positonChooser == 2) {
					state = State::Multiplayer;
				}
				if (positonChooser == 3) {
					state = State::Plateformer;
				}
			}
		}
	}
}
Game::State Game::update(State state) {
	switch (state) {
	case State::Welcome:
		if (false) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::StartMenu:
		if (false) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::GameModeChooser:
		gamemodechooser(state);
		return state;
		break;
	case State::Options:
		if (false) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::SinglePlayer:
		if (Transaction::getInstance().conditionGameOver(GameSinglePlayer::getInstance().snake())) {
			return State::GameOver;
		}
		else {
			GameSinglePlayer::getInstance().generateFruit();
			GameSinglePlayer::getInstance().generateSnake();
			return State::SinglePlayer;
		}
		break;
	case State::Multiplayer:
		if (false) {
			return State::GameOver;
		}
		else {
			GameMultiPlayer::getInstance().generateFruit();
			GameMultiPlayer::getInstance().generateSnake();
			return State::Multiplayer;
		}
		break;
	case State::Plateformer:
		if (false) {
			return State::GameOver;
		}
		else {
			return State::Plateformer;
		}
		break;
	case State::GameOver:
		if (false) {
			return State::GameOver;
		}
		else {
			return State::GameOver;
		}
		break;
	}
}

void Game::start(size_t width, size_t height) {

	ConsoleContext context(800, 800, "The Snake Game", 8, 8, L"Consolas");
	Console::defineContext(context);
	Game::getInstance().reader_m = &( Console::getInstance().keyReader());
	Game::getInstance().gameLoop(State::GameModeChooser);
}

