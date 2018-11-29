#include "YellowFruit.h"


YellowFruit::YellowFruit()
	: Fruit(),
	mSpeedReducor{0.0f}
{
}

YellowFruit::YellowFruit(float speedReducor)
	: Fruit(),
	mSpeedReducor{speedReducor}
{
}

YellowFruit::YellowFruit(Point &p, int pointVal, float speedReducor)
	: Fruit(p, pointVal),
	mSpeedReducor{speedReducor}
{
}

YellowFruit::~YellowFruit()
{
}

float YellowFruit::getSpeedReducer()
{
	return mSpeedReducor;
}
