#include "SinglePlayerAutomaton.h"

SinglePlayerAutomaton::SinglePlayerAutomaton()
	:slow_m{500},
	mStartedAutomaton{true}
{
}

SinglePlayerAutomaton::~SinglePlayerAutomaton()
{
}


void SinglePlayerAutomaton::startSinglePlayerAutomaton(SinglePlayerState state)
{
	state = update(state);
}

void SinglePlayerAutomaton::resumeSinglePlayerAutomaton(SinglePlayerState state)
{
	state = update(state);
}

bool SinglePlayerAutomaton::startedAutomaton() const
{
	//Crée un fruit au démarrage de l'automate
	GameSinglePlayer::getInstance().generateFruit();
	return mStartedAutomaton;
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::nextSinglePlayerState(SinglePlayerState state)
{
	//Change l'état prochain 
	return (SinglePlayerState)((int)state +1);
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::update(SinglePlayerState state)
{
	switch (state) {
	case SinglePlayerState::Idle:
		if (true) {
			return nextSinglePlayerState(state);
		}
		//S'il n'y a pas d'input de key
		else {
			return state;
		}
		break;
	case SinglePlayerState::Move:
		//avance automatiquement
		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			return SinglePlayerState::Collision;
		}

		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GameSinglePlayer::getInstance().snake(), GameSinglePlayer::getInstance().fruit())) {
			if (GameSinglePlayer::getInstance().fruit()) {
				GameSinglePlayer::getInstance().fruit()->beEaten(GameSinglePlayer::getInstance().snake());
				GameSinglePlayer::getInstance().generateFruit();
			}
			return nextSinglePlayerState(state);
		}

		else if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				//Change sa direction
				changeDirection(k);
			}
			//Le déplace
			GameSinglePlayer::getInstance().slitherSnake();
			return SinglePlayerState::Move;
		}
		else {
			//avance automatiquement
			GameSinglePlayer::getInstance().slitherSnake();
			return SinglePlayerState::Move;
		}
		break;
	case SinglePlayerState::Eat:
			//GameSinglePlayer::getInstance().generateFruit(true);
			return SinglePlayerState::Move;
		break;
	case SinglePlayerState::Collision:
		Game::getInstance().changeKnownState(Game::State::GameOver);
			return nextSinglePlayerState(state);
		break;
	case SinglePlayerState::EndGame:
		Game::getInstance().changeKnownState(Game::State::GameOver);
		return SinglePlayerState::Idle;
		break;
	default:
		return SinglePlayerState::Idle;
}
}

bool SinglePlayerAutomaton::changeDirection(ConsoleKeyEvent &k)
{
	//Autorise le changement de direction seulement si ce n'est pas dans le sens directement opposé
	if (k.keyV() == VK_UP)
		if ((GameSinglePlayer::getInstance().snake()).curDirection() == Snake::Direction::Down)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Up);
	else if (k.keyV() == VK_DOWN)
		if ((GameSinglePlayer::getInstance().snake()).curDirection() == Snake::Direction::Up)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Down);
	else if (k.keyV() == VK_LEFT)
		if ((GameSinglePlayer::getInstance().snake()).curDirection() == Snake::Direction::Right)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Left);
	else {
		if ((GameSinglePlayer::getInstance().snake()).curDirection() == Snake::Direction::Left)
			return false;
		else
			GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Right);
	}
}