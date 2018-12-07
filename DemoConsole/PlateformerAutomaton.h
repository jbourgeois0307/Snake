#ifndef PLATEFORMER_AUTOMATON_H
#define PLATEFORMER_AUTOMATON_H

#include "Transactions.h"
#include "Snake.h"
#include "Game.h"

class PlateformerAutomaton
{
private:
	PlateformerAutomaton();
	~PlateformerAutomaton();
public:
	enum class PlateformerState { Idle, Move, Eat, Collision, EndGame };
	static PlateformerAutomaton& getInstance()
	{
		static PlateformerAutomaton instance;
		return instance;
	}
	void startPlateformerAutomaton(PlateformerState state = PlateformerState::Idle);
	void resumePlateformerAutomaton(PlateformerState state);
	void resetPlateformerAutomaton();
	bool startedAutomaton() const;
private:
	PlateformerState mState;
	PlateformerState nextPlateformerState(PlateformerState state);
	PlateformerState update(PlateformerState state);
	void moveObstacles();
	bool changeDirection(ConsoleKeyEvent &k);
	size_t slow_m;
	bool mStartedAutomaton;
};

#endif