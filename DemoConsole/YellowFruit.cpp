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

YellowFruit::YellowFruit(int x, int y, int pointVal, float speedReducor)
	: Fruit(x, y, pointVal),
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
