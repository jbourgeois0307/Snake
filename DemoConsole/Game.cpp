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

	timer.start();
	while (true)
	{
		ConsoleKeyEvent::KeyState::KeyDown;

		processInput();
		state = update(state);
		render(state);
		timer.restart();
		int timertime = timer.elapsed();
		while (timertime <= 65000000) {
			timertime = timer.elapsed();

		}
	}
}
void Game::processInput() {
	reader_m->read(keyEvents);
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

ConsoleKeyReader::KeyEvents Game::getKeyEvents() const
{
	return keyEvents;
}

bool Game::anyTouch() {
	if (keyEvents.size() > 0)
	{
		//size_t size = keyEvents.size();
		keyEvents.clear();
		//for (int i = 0; i < size; ++i) {
		//	keyEvents.pop_back();
		//}
		return true;
	}
	else {
	return false;
	}
}

void Game::changeKnownState(State state)
{
	update(state);
}



void Game::gamemodechooser(State& state){
	if (keyEvents.size() > 0) {
		for (auto &event : keyEvents) {
			if (event.keyA() == '1')
			{
				positonChooser = 1;
			}
			if (event.keyA() == '2')
			{
				positonChooser = 2;
			}
			if (event.keyA() == '3')
			{
				positonChooser = 3;
			}
			int keyevent = event.keyA();
			if (event.keyV() == VK_UP) {
				test();
			}
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
		if (anyTouch()) {
			return State::GameModeChooser;
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
		if (Transaction::getInstance().conditionPause(getKeyEvents()))
			return testPause(State::SinglePlayer);

		if (!SinglePlayerAutomaton::getInstance().startedAutomaton()) {
			GameSinglePlayer::getInstance().play();
			
			return State::SinglePlayer;
		}

		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			SinglePlayerAutomaton::getInstance().resetSinglePlayerAutomaton();
			return State::GameOver;
		}

		else {
			SinglePlayerAutomaton::getInstance().resumeSinglePlayerAutomaton();
			return State::SinglePlayer;
		}
		break;
	case State::Multiplayer:
		if (Transaction::getInstance().conditionPause(getKeyEvents()))
			return testPause(State::Multiplayer);
		if (!MultiPlayerAutomaton::getInstance().startedAutomaton()) {
			GameMultiPlayer::getInstance().play();
			return State::Multiplayer;
		}

		if (Transaction::getInstance().conditionSnakeCollision(GameMultiPlayer::getInstance().snake(), GameMultiPlayer::getInstance().caterpillar())) {
			MultiPlayerAutomaton::getInstance().resetMultiPlayerAutomaton();
			return State::GameOver;
		}
		else {
			MultiPlayerAutomaton::getInstance().resumeMultiPlayerAutomaton();
			return State::Multiplayer;
		}
		break;
	case State::Plateformer:
		if (Transaction::getInstance().conditionPause(getKeyEvents()))
			testPause(State::Plateformer);
		if (Transaction::getInstance().conditionSnakeCollision(GameMultiPlayer::getInstance().snake())) {
			return State::GameOver;
		}
		else {
			GamePlateformer::getInstance().generateFruit();
			GamePlateformer::getInstance().generateSnake();
			GamePlateformer::getInstance().generateObstacles();
			return nextState(state);
		}
		break;
	case State::GameOver:
		if (anyTouch()) {
			return State::GameModeChooser;
		}
		else {
			return state;
		}
		break;
	case State::PauseSinglePlayer:
		testPause(State::SinglePlayer);
		break;
	case State::PauseMultiPlayer:
		testPause(State::Multiplayer);
		break;
	default:
		return State::GameOver;
	}
}

void Game::start(size_t width, size_t height) {

	ConsoleContext context(800, 800, "The Snake Game", 9, 9, L"Consolas");
	Console::defineContext(context);
	Game::getInstance().reader_m = &( Console::getInstance().keyReader());
	Game::getInstance().gameLoop(State::Welcome);
}

void Game::test() {
	while (true) {
		writer->randomize();
	}
}

Game::State Game::testPause(State state)
{

	if (!Transaction::getInstance().conditionPause(getKeyEvents())) {
		if (state == State::SinglePlayer)
			return State::PauseSinglePlayer;
		else
			return State::PauseMultiPlayer;
	}
	else {
		return state;
	}
}