#include "RedFruit.h"

RedFruit::RedFruit()
	: Fruit()
{
}

RedFruit::RedFruit(Point const &p, int pointVal, FruitType c)
	: Fruit(p,pointVal,c)
{
	//Incrémente un compteur de fruit propre à la classe
	sCountFruit++;
}

RedFruit::~RedFruit()
{
}

void RedFruit::beEaten(Snake * snake)
{
	snake->addBodPart(Fruit::mPointVal);
}