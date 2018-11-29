#include "Console.h"
#include "GameArea.h"

class Game
{
private:
	Game();
	~Game();
public:
	void static start(size_t width=800, size_t height=1000);
	
	void generateGameArea();
	void generateSnake();
	void generateApple();
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}
private:
	void boucleDeJeu(int state = 1);
	
};

