#include "Snake.h"

Snake::Snake()
{
}

//Constructeur qui demande la vitesse et positionne la tête à (50,50)
Snake::Snake(float speed)
	: mSpeed{ speed },
	mBodLength { 4 }
{
	Point p = Point(50, 50);
	mBodPart.insert(mBodPart.begin(), p);
	for (int b{ 1 }; b <= mBodLength; ++b)
	{
		mBodPart.insert((mBodPart.begin() + b), Point(p.x(), p.y() + b));
	}
}

//Constructeur qui requiert vitesse et positions de la tête initiales
Snake::Snake(float speed, Point &p)
	: mSpeed{speed},
	mBodLength { 4 }
{
	mBodPart.insert(mBodPart.begin(), p);
	for (int b{ 1 }; b <= mBodLength; ++b)
	{
		mBodPart.insert((mBodPart.begin() + b),Point(p.x(),p.y()+b));
	}
}

Snake::~Snake()
{
}

//Fait avancer le serpent ainsi que sa queue
void Snake::slither(Point &p)
{
	//avance la queue du serpent en premier
	for (int b{ 1 };b<=static_cast<int>(mBodPart.size());++b)
	{	
		(mBodPart.begin() + b) = (mBodPart.begin()-b);
	}
	//La tête se place au point demandé
	slitherHead(p);
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

void Snake::speed(float speedModifier) 
{
	mSpeed *= speedModifier;
}

int Snake::bodLength()
{
	return mBodLength;
}

std::vector<Point> Snake::bodPart()
{
	return std::vector<Point>();
}

void Snake::slitherHead(Point &p)
{
	mBodPart.front() = p;
}
