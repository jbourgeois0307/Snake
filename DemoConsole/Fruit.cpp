#include "Fruit.h"

Fruit::Fruit()
	: mPoint(0,0),
	mPointVal{ 0 }
{
}

Fruit::Fruit(Point p, int pointVal)
	: mPoint{p},
	mPointVal{pointVal}
{
}

Fruit::~Fruit()
{
}

void Fruit::setPoint(Point p)
{
	mPoint=p;
}

int Fruit::pointVal()
{
	return mPointVal;
}

Point Fruit::point()
{
	return mPoint;
}
