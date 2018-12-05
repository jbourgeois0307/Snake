#ifndef SINGLEPLAYER_AUTOMATON_H
#define SINGLEPLAYER_AUTOMATON_H

#include "Transactions.h"
#include "Snake.h"
#include "Game.h"

class SinglePlayerAutomaton
{
private:
	SinglePlayerAutomaton();
	~SinglePlayerAutomaton();
public:
	enum class SinglePlayerState { Idle, Move, Eat, Collision, EndGame };
	static SinglePlayerAutomaton& getInstance()
	{
		static SinglePlayerAutomaton instance;
		return instance;
	}
	void startSinglePlayerAutomaton(SinglePlayerState state = SinglePlayerState::Idle);
	void resumeSinglePlayerAutomaton(SinglePlayerState state);
	bool startedAutomaton() const;
private:
	SinglePlayerState nextSinglePlayerState(SinglePlayerState state);
	SinglePlayerState update(SinglePlayerState state);
	bool changeDirection(ConsoleKeyEvent &k);
	size_t slow_m;
	bool mStartedAutomaton;
};


#endif //SINGLEPLAYER_AUTOMATON_H
