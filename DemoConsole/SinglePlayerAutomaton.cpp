#include "SinglePlayerAutomaton.h"

SinglePlayerAutomaton::SinglePlayerAutomaton()
{
}

SinglePlayerAutomaton::~SinglePlayerAutomaton()
{
}

SinglePlayerAutomaton::State SinglePlayerAutomaton::nextState(State state)
{
	//Change l'état prochain 
	return (State)((int)state+1);
}

void SinglePlayerAutomaton::startSinglePlayerAutomaton(State state)
{
	//Part le timer de l'automate
//	mTimer.start();
}

SinglePlayerAutomaton::State SinglePlayerAutomaton::update(State state)
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
}