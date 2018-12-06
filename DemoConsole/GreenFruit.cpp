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

GreenFruit::GreenFruit(Point const &p, int pointVal, float speedAmplifier, FruitType c)
	: Fruit(p, pointVal,c),
	mSpeedAmplifier{speedAmplifier}
{
	//Incrémente un compteur de fruit propre à la classe
	sCountFruit++;
}

GreenFruit::~GreenFruit()
{
}

float GreenFruit::getSpeedAmplificator()
{
	return mSpeedAmplifier;
}

void GreenFruit::beEaten(Snake * snake)
{
	snake->addBodPart(Fruit::mPointVal);
	snake->speed(mSpeedAmplifier);
}

