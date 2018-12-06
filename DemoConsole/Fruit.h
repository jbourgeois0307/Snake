#ifndef FRUIT_H
#define FRUIT_H

#include "Point.h"
#include "Snake.h"

class Fruit
{
protected:
	Point mPoint;
	int  mPointVal;

public:
	enum class FruitType { Red, Purple, Yellow, Green };
	inline static int sCountFruit = 0;
protected:
	FruitType mColor;
public:
	Fruit();
	Fruit(Point p, int pointVal, FruitType c);
	~Fruit();
	void setPoint(Point p);
	int pointVal();
	Point point();
	FruitType color();
	virtual void beEaten(Snake *snake)=0;
};




#endif //FRUIT_H
