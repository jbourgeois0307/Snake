#include "SinglePlayerAutomaton.h"

SinglePlayerAutomation::SinglePlayerAutomation()
{
}

SinglePlayerAutomation::~SinglePlayerAutomation()
{
}

SinglePlayerAutomation::State SinglePlayerAutomation::nextState(State state)
{
	//Change l'état prochain 
	return (State)((int)state+1);
}

void SinglePlayerAutomation::startSinglePlayerAutomation(State state)
{
	//Part le timer de l'automate
//	mTimer.start();
}

/*SinglePlayerAutomation::State SinglePlayerAutomation::update(State state)
{
	switch (state) {
	case State::Idle:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::Move:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::Eat:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::Nothing:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::Collision:
		if (true) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::EndGame:
		if (true) {
			return nextState(state);
		}
		else {
			return State::Idle;
		}
		break;
}
}*/