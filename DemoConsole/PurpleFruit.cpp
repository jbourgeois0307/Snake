#include "PurpleFruit.h"

PurpleFruit::PurpleFruit()
	: Fruit(),
	mPointPenalty{0}
{
}

PurpleFruit::PurpleFruit(int x, int y, int pointVal)
	: Fruit (x,y,pointVal)
{
}

PurpleFruit::~PurpleFruit()
{
}

int PurpleFruit::getPointPenaltyVal()
{
	return mPointPenalty;
}
