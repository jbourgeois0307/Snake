#include "GreenFruit.h"

GreenFruit::GreenFruit()
	: Fruit(),
	mSpeedAmplifier{ 0.0f }
{
}

GreenFruit::GreenFruit(float speedAmplifier)
	: Fruit(),
	mSpeedAmplifier{ speedAmplifier }
{
}

GreenFruit::GreenFruit(int x, int y, int pointVal, float speedAmplifier)
	: Fruit(x,y, pointVal),
	mSpeedAmplifier{speedAmplifier}
{
}

GreenFruit::~GreenFruit()
{
}

float GreenFruit::getSpeedAmplificator()
{
	return mSpeedAmplifier;
}

