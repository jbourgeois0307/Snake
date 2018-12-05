#include "Fruit.h"

Fruit::Fruit()
	: mPoint(0,0),
	mPointVal{ 0 },
	mColor{ 0 }
{
}

Fruit::Fruit(Point p, int pointVal, FruitType c)
	: mPoint{p},
	mPointVal{pointVal},
	mColor{c}
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

Fruit::FruitType Fruit::color()
{
	return mColor;
}
