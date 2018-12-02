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
		if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				if (k.keyV() == VK_UP)
					GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Up);
				else if(k.keyV() == VK_DOWN)
					GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Down);
				else if (k.keyV() == VK_LEFT)
					GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Left);
				else if (k.keyV() == VK_RIGHT)
					GameSinglePlayer::getInstance().directionSnake(Snake::Direction::Right);
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
		//S'il y a une collision
		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			return SinglePlayerState::Collision;
		}
		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GameSinglePlayer::getInstance().snake(),GameSinglePlayer::getInstance().fruit())) {
			return nextSinglePlayerState(state);
		}
		else {
			return SinglePlayerState::Move;
		}
		break;
	case SinglePlayerState::Eat:
		if (true) {
			return nextSinglePlayerState(state);
		}
		else {
			return state;
		}
		break;
	case SinglePlayerState::Collision:
		if (true) {
			return nextSinglePlayerState(state);
		}
		else {
			return state;
		}
		break;
	case SinglePlayerState::EndGame:
		return SinglePlayerState::Idle;
		break;
}
}