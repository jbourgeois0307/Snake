#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Fruit.h"
#include "Point.h"
class Snake
{
	int mBodLength;
	float mSpeed;
	std::vector<Point> mBodPart;

public:
	Snake();
	Snake(float speed);
	Snake(float speed, Point &initP);
	~Snake();
	void slither(Point &p);
	void slitherHead(Point &p);
	void eatFruit(Fruit &fruit);
	void addTail(int addedLength);
	void cutTail(int cuttedLength);
	void speed(float speedModifier);
	int bodLength();
	std::vector<Point> bodPart();
};


#endif //SNAKE_H
