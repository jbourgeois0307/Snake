#ifndef GAME_H
#define GAME_H

#include "Console.h"
#include "GameSinglePlayer.h"
#include "GameArea.h"
#include "ElapsedTimer.h"

class Game
{
private:
	Game();
	~Game();
public:
	void static start(size_t width=800, size_t height= 800);
	enum class State {Welcome, StartMenu, GameModeChooser, Options, SinglePlayer, Multiplayer, Plateformer, GameOver};
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

private:
	State nextState(State state);
	void gameLoop(State state = State::Welcome);
	void processInput();
	State update(State state);
	void render(State state);
	ElapsedTimer <>timer;
	size_t slow_m;
	ConsoleKeyReader * reader_m;
	ConsoleKeyReader::KeyEvents keyEvents;
};



#endif