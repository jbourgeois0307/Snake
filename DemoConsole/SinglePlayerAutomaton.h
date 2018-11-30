#ifndef SINGLEPLAYER_AUTOMATON_H
#define SINGLEPLAYER_AUTOMATON_H

//#include "ElapsedTimer.h"

class SinglePlayerAutomation
{
private:
	SinglePlayerAutomation();
	~SinglePlayerAutomation();
public:
	static SinglePlayerAutomation& getInstance()
	{
		static SinglePlayerAutomation instance;
		return instance;
	}
	enum class State {Idle, Move, Eat, Nothing, Collision, EndGame};
private:
	State nextState(State state);
	void startSinglePlayerAutomation(State state = State::Idle);
	State update(State state);
//	ElapsedTimer<> mTimer;
	size_t slow_m;
};


#endif //SINGLEPLAYER_AUTOMATON_H
