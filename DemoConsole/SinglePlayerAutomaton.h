#ifndef SINGLEPLAYER_AUTOMATON_H
#define SINGLEPLAYER_AUTOMATON_H

//#include "ElapsedTimer.h"
#include "Transactions.h"
#include "Snake.h"
#include "Game.h"

class SinglePlayerAutomaton
{
private:
	SinglePlayerAutomaton();
	SinglePlayerAutomaton(Snake snake);
	~SinglePlayerAutomaton();
public:
	enum class SinglePlayerState { Idle, Move, Eat, Collision, EndGame };
	static SinglePlayerAutomaton& getInstance(Snake snake)
	{
		static SinglePlayerAutomaton instance;
		return instance;
	}
	void startSinglePlayerAutomaton(SinglePlayerState state = SinglePlayerState::Idle);
private:
	SinglePlayerState mCurState;
	Snake mSnake;
	SinglePlayerState nextSinglePlayerState(SinglePlayerState state);
	SinglePlayerState update(SinglePlayerState state);
	//ElapsedTimer<> mTimer;
	size_t slow_m;
};


#endif //SINGLEPLAYER_AUTOMATON_H
