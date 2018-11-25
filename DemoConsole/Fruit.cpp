#include "Fruit.h"

Fruit::Fruit()
	: mX {50},
	  mY {50}
{
}

Fruit::Fruit(int x, int y, int pointVal)
	: mX{x},
	mY{y},
	mPointVal{pointVal}
{
}

Fruit::~Fruit()
{
}

void Fruit::setX(int x)
{
	Fruit::mX = x;
}

void Fruit::setY(int y)
{
	Fruit::mY = y;
}

int Fruit::getMX()
{
	return mX;
}

int Fruit::getMY()
{
	return mY;
}

int Fruit::getMPointVal()
{
	return mPointVal;
}


void Fruit::destroyFruit()
{
	Fruit::~Fruit();
}

