#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
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
	Snake(float speed, Point & p, int size);
	~Snake();
	enum class Direction { Up, Down, Left, Right };
	void slither();
	void slitherHead();
	void addBodPart(int addedLength);
	void cutTail(int cuttedLength);
	bool checkCollisionHead();
	bool checkCollisionAdversary(Snake * adversary);
	bool checkCollisionPoint(Point & p);
	bool checkCollisionWall();
	void speed(float speedModifier);
	void setCurDirection(Direction direction);
	Direction& curDirection();
	int bodLength();
	std::vector<Point> bodPart();
	void nextPoint(Point &point);
private:
	Direction mCurDirection;
};


#endif //SNAKE_H
