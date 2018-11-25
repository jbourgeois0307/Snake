#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Fruit.h"

class Snake
{
	int mBodLength;
	float mSpeed;
	std::vector<int> mXPerBodPart;
	std::vector<int> mYPerBodPart;

public:
	Snake();
	Snake(float speed);
	Snake(float speed, int initX, int initY);
	~Snake();
	void slither(int x, int y);
	void eatFruit(Fruit &fruit);
	void addTail(int addedLength);
	void cutTail(int cuttedLength);
	void moveX(int x);
	void moveY(int y);
	void speed(float speedModifier);
};


#endif //SNAKE_H
