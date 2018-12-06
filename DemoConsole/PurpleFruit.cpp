#include "PurpleFruit.h"

PurpleFruit::PurpleFruit()
	: Fruit(),
	mPointPenalty{0}
{
}

PurpleFruit::PurpleFruit(Point &p, int pointVal, FruitType c)
	: Fruit (p,pointVal,c)
{
	//Incr�mente un compteur de fruit propre � la classe
	sCountFruit++;
}

PurpleFruit::~PurpleFruit()
{
}

int PurpleFruit::getPointPenaltyVal()
{
	return mPointPenalty;
}

void PurpleFruit::beEaten(Snake * snake)
{
	snake->addBodPart(Fruit::mPointVal);
}
