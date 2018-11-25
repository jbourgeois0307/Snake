#include "Fruit.h"

Fruit::Fruit()
	: mX {50},
	  mY {50}
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

void Fruit::destroyFruit()
{
	Fruit::~Fruit();
}

