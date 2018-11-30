#include "SinglePlayerAutomaton.h"

SinglePlayerAutomaton::SinglePlayerAutomaton()
{
}

SinglePlayerAutomaton::SinglePlayerAutomaton(Snake snake)
	: mSnake{snake}
{
	//Entame la machine de Single Player
	startSinglePlayerAutomaton();
}

SinglePlayerAutomaton::~SinglePlayerAutomaton()
{
}

void SinglePlayerAutomaton::start()
{
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::nextSinglePlayerState(SinglePlayerState mCurState)
{
	//Change l'état prochain 
	return (SinglePlayerState)((int)mCurState +1);
}

void SinglePlayerAutomaton::startSinglePlayerAutomaton(SinglePlayerState mCurState)
{
	//Part le timer de l'automate
	//	mTimer.start();
	update(mCurState);
}

SinglePlayerAutomaton::SinglePlayerState SinglePlayerAutomaton::update(SinglePlayerState mCurState)
{
	switch (mCurState) {
	case SinglePlayerState::Idle:
		if (true) {
			return nextSinglePlayerState(mCurState);
		}
		else {
			return mCurState;
		}
		break;
	case SinglePlayerState::Move:
		if (Transaction::getInstance().conditionSnakeCollision(GameSinglePlayer::getInstance().snake())) {
			return SinglePlayerState::Collision;
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
	case SinglePlayerState::Nothing:
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