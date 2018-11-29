#pragma once
class Game
{
public:
	Game();
	~Game();
	void static start(size_t width=800, size_t height=600);
	
	void generateGameArea();
	void generateSnake();
	void generateApple();

	
};

