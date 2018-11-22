#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
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
	void eatFruit(int speedAmplifier);
	void eatFruit(int speedAmplifier, int tailLength);
	void addTail(int addedLength);
	void cutTail(int cuttedLength);
	void moveX(int x);
	void moveY(int y);
};


#endif //SNAKE_H
