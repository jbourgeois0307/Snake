#include "RedFruit.h"

RedFruit::RedFruit()
	: Fruit()
{
}

RedFruit::RedFruit(Point const &p, int pointVal)
	: Fruit(p,pointVal)
{
}

RedFruit::~RedFruit()
{
}

void RedFruit::beEaten(Snake * snake)
{
	snake->addBodPart(mPointVal);
}
