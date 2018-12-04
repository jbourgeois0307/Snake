#ifndef MULTIPLAYER_AUTOMATON_H
#define MULTIPLAYER_AUTOMATON_H

#include "Transactions.h"
#include "Snake.h"
#include "Game.h"

class MultiPlayerAutomaton
{
private:
	MultiPlayerAutomaton();
	~MultiPlayerAutomaton();
public:
	enum class MultiPlayerState { Idle, Move, Eat, Collision, EndGame };
	static MultiPlayerAutomaton& getInstance()
	{
		static MultiPlayerAutomaton instance;
		return instance;
	}
	void startMultiPlayerAutomaton(MultiPlayerState state = MultiPlayerState::Move);
	void resumeMultiPlayerAutomaton(MultiPlayerState state);
	bool startedAutomaton() const;
private:
	MultiPlayerState nextMultiPlayerState(MultiPlayerState state);
	MultiPlayerState update(MultiPlayerState state);
	bool changeDirection(ConsoleKeyEvent &k);
	size_t slow_m;
	bool mStartedAutomaton;
};

#endif