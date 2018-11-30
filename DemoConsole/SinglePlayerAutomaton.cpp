#include "SinglePlayerAutomaton.h"

SinglePlayerAutomaton::SinglePlayerAutomaton()
{
}

SinglePlayerAutomaton::SinglePlayerAutomaton(Snake snake)
	: mSnake{snake},
	slow_m{500}
{
}

SinglePlayerAutomaton::~SinglePlayerAutomaton()
{
}


void SinglePlayerAutomaton::startSinglePlayerAutomaton(SinglePlayerState state)
{

	//Part le timer de l'automate
	//	mTimer.start();
	update(mCurState);
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::nextSinglePlayerState(SinglePlayerState mCurState)
{
	//Change l'état prochain 
	return (SinglePlayerState)((int)mCurState +1);
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::update(SinglePlayerState mCurState)
{
	switch (mCurState) {
	case SinglePlayerState::Idle:
		if (true) {
			return nextSinglePlayerState(mCurState);
		}
		//S'il n'y a pas d'input de key
		else {
			return mCurState;
		}
		break;
	case SinglePlayerState::Move:
		//avance automatiquement
		if (Transaction::getInstance().conditionMoveInput(Game::getInstance().getKeyEvents())) {
			//Change sa direction
			for (auto &k : Game::getInstance().getKeyEvents())
			{
				if (k.keyV() == VK_UP)
					GameSinglePlayer::getInstance().snake().setCurDirection(Snake::Direction::Up);
				else if(k.keyV() == VK_DOWN)
					GameSinglePlayer::getInstance().snake().setCurDirection(Snake::Direction::Down);
				else if (k.keyV() == VK_LEFT)
					GameSinglePlayer::getInstance().snake().setCurDirection(Snake::Direction::Left);
				else if (k.keyV() == VK_RIGHT)
					GameSinglePlayer::getInstance().snake().setCurDirection(Snake::Direction::Right);
			}
			
			//Le déplace
			GameSinglePlayer::getInstance().snake().slither();
		}
		else
			//avance automatiquement
			GameSinglePlayer::getInstance().snake().slither();
		//S'il y a une collision
		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			return SinglePlayerState::Collision;
		}
		//s'il mange un fruit
		else if (Transaction::getInstance().conditionSnakeEat(GameSinglePlayer::getInstance().snake(),GameSinglePlayer::getInstance().fruit())) {
			return nextSinglePlayerState(mCurState);
		}
		else {
			return nextSinglePlayerState(mCurState);
		}
		break;
	case SinglePlayerState::Eat:
		if (true) {
			return nextSinglePlayerState(mCurState);
		}
		else {
			return mCurState;
		}
		break;
	case SinglePlayerState::Collision:
		if (true) {
			return nextSinglePlayerState(mCurState);
		}
		else {
			return mCurState;
		}
		break;
	case SinglePlayerState::EndGame:
		if (true) {
			return nextSinglePlayerState(mCurState);
		}
		else {
			return SinglePlayerState::Idle;
		}
		break;
}
}