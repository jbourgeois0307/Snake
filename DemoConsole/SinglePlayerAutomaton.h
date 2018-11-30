#ifndef SINGLEPLAYER_AUTOMATON_H
#define SINGLEPLAYER_AUTOMATON_H

//#include "ElapsedTimer.h"

class SinglePlayerAutomaton
{
private:
	SinglePlayerAutomaton();
	~SinglePlayerAutomaton();
public:
	void static start();
	enum class State { Idle, Move, Eat, Nothing, Collision, EndGame };
	static SinglePlayerAutomaton& getInstance()
	{
		static SinglePlayerAutomaton instance;
		return instance;
	}
	
private:
	State nextState(State state);
	void startSinglePlayerAutomaton(State state = State::Idle);
	State update(State state);
	//ElapsedTimer<> mTimer;
	size_t slow_m;
};


#endif //SINGLEPLAYER_AUTOMATON_H
