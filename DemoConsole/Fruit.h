#ifndef FRUIT_H
#define FRUIT_H

#include "Point.h"
#include "Snake.h"

class Fruit
{
	static int sCountFruit;
protected:
	Point mPoint;
	int  mPointVal;
public:
	Fruit();
	Fruit(Point p, int pointVal);
	~Fruit();
	void setPoint(Point p);
	int pointVal();
	Point point();
	virtual void beEaten(Snake *snake)=0;
};




#endif //FRUIT_H
