#include "PurpleFruit.h"

PurpleFruit::PurpleFruit()
	: Fruit(),
	mPointPenalty{0}
{
}

PurpleFruit::PurpleFruit(Point &p, int pointVal)
	: Fruit (p,pointVal)
{
}

PurpleFruit::~PurpleFruit()
{
}

int PurpleFruit::getPointPenaltyVal()
{
	return mPointPenalty;
}

void PurpleFruit::beEaten(Snake & snake)
{
	snake.addBodPart(mPointVal);
}
