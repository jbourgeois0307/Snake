#include "Snake.h"

Snake::Snake()
{
}

//Constructeur qui demande la vitesse et positionne la tête à (50,50)
Snake::Snake(float speed)
	: mSpeed{ speed },
	mBodLength { 4 }
{
	mXPerBodPart.insert(mXPerBodPart.begin(), 50);
	mYPerBodPart.insert(mYPerBodPart.begin(), 50);
}

//Constructeur qui requiert vitesse et positions de la tête initiales
Snake::Snake(float speed, int initX, int initY)
	: mSpeed{speed},
	mBodLength { 4 }
{
	mXPerBodPart.insert(mXPerBodPart.begin(),initX);
	mYPerBodPart.insert(mYPerBodPart.begin(),initY);
}

Snake::~Snake()
{
}

//Fait avancer le serpent ainsi que sa queue
void Snake::slither(int x, int y)
{
	Snake::moveX(x);
	Snake::moveY(y);
}

void Snake::eatFruit(Fruit &fruit)
{
	//ptr temporaire pour connaitre la sous-classe du fruit
	Fruit *tempPtr = &fruit;

	////La queue du serpent s'allonge selon la valeur du fruit
	//mBodLength += fruit.getMPointVal();
	//if (dynamic_cast <GreenFruit*>(tempPtr) != nullptr || dynamic_cast <YellowFruit*>(tempPtr) != nullptr)
	//{
	//	speed(fruit.getSpeedAmplificator());
	//}
	////ICI CONTINUER AVEC D'AUTRES SOUS-CLASSE DE SOUS-FRUIT (25 nov)
	//else if ()
	//{
	//
	//}

}

void Snake::moveX(int x)
{
	for (auto xBod : mXPerBodPart)
	{
		xBod += x;
	}
}

void Snake::moveY(int y)
{
	for (auto yBod : mYPerBodPart)
	{
		yBod += y;
	}
}

void Snake::speed(float speedModifier) 
{
	mSpeed *= speedModifier;
}
