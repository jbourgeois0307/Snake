#ifndef FRUIT_H
#define FRUIT_H

#include "Point.h"

class Fruit
{
	static int sCountFruit;
	Point mPoint;
	int  mPointVal;
public:
	Fruit();
	Fruit(Point &p, int pointVal);
	~Fruit();
	void setPoint(Point &p);
	int pointVal();
	Point point();
	void destroyFruit();
};




#endif //FRUIT_H
