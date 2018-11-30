#ifndef SINGLEPLAYER_AUTOMATON_H
#define SINGLEPLAYER_AUTOMATON_H

//#include "ElapsedTimer.h"
#include "Transactions.h"
#include "Snake.h"

class SinglePlayerAutomaton
{
private:
	SinglePlayerAutomaton();
	SinglePlayerAutomaton(Snake snake);
	~SinglePlayerAutomaton();
public:
	void static start();
	enum class SinglePlayerState { Idle, Move, Eat, Nothing, Collision, EndGame };
	static SinglePlayerAutomaton& getInstance()
	{
		static SinglePlayerAutomaton instance;
		return instance;
	}
	
private:
	SinglePlayerState mCurState;
	Snake mSnake;
	SinglePlayerState nextSinglePlayerState(SinglePlayerState state);
	void startSinglePlayerAutomaton(SinglePlayerState state = SinglePlayerState::Idle);
	SinglePlayerState update(SinglePlayerState state);
	//ElapsedTimer<> mTimer;
	size_t slow_m;
};


#endif //SINGLEPLAYER_AUTOMATON_H
