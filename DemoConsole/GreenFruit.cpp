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

GreenFruit::GreenFruit(Point &p, int pointVal, float speedAmplifier)
	: Fruit(p, pointVal),
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

