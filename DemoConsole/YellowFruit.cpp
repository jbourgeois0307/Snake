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

YellowFruit::YellowFruit(Point &p, int pointVal, float speedReducor, FruitType c)
	: Fruit(p, pointVal,c),
	mSpeedReducor{speedReducor}
{
	//Incr�mente un compteur de fruit propre � la classe
	sCountFruit++;
}

YellowFruit::~YellowFruit()
{
}

float YellowFruit::getSpeedReducer()
{
	return mSpeedReducor;
}

void YellowFruit::beEaten(Snake * snake)
{
	snake->addBodPart(Fruit::mPointVal);
}
