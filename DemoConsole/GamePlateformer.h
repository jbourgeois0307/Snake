#ifndef PLATEFORMER_H
#define PLATEFORMER_H


#include "Console.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"
#include "Snake.h"
#include "Obstacle.h"

class GamePlateformer
{
protected:
	GamePlateformer();
	~GamePlateformer();

	bool haveFruit_m;
	bool snakeExist_m;
	Fruit *fruit_m;
	Snake snake_m;
	size_t mNbFruit;
	std::vector<Obstacle> obstacles;


public:
	static GamePlateformer& getInstance()
	{
		static GamePlateformer instance;
		return instance;
	}

	bool play();
	void generateFruit();
	void generateSnake();
	void generateObstacles();
	void showSnake(ConsoleImage & image);
	void showObstacles(ConsoleImage & image);
	void showFruit(ConsoleImage & image);
	void slitherSnake();
	void directionSnake(Snake::Direction direction);
	Snake::Direction& curDirection();
	Snake& snake();
	Fruit* fruit();
	
};

#endif