#include "Snake.h"

Snake::Snake()
{
}

//Constructeur qui demande la vitesse et positionne la tête à (50,50)
Snake::Snake(float speed)
	: mSpeed{ speed },
	mBodLength{ 10 },
	mCurDirection{ Direction::Up }
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
	mBodLength { 10 },
	mCurDirection{ Direction::Up }
{
	mBodPart.insert(mBodPart.begin(), p);
	for (int b{ 1 }; b <= mBodLength; ++b)
	{
		mBodPart.insert((mBodPart.begin() + b), Point(p.x(), p.y() + b));
	}
}

Snake::~Snake()
{
}

//Fait avancer le serpent ainsi que sa queue
void Snake::slither()
{
	Point temp = mBodPart.front();
	//avance la queue du serpent en premier par rotation
	std::rotate(mBodPart.begin(), mBodPart.begin()+(mBodLength), mBodPart.end());
	mBodPart.front() = temp;
	//La tête se place au point demandé
	slitherHead();
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

bool Snake::checkCollisionHead() {
	for (int i{ 1 }; i < mBodLength - 1; ++i) {
		if (mBodPart.at(0).x() == mBodPart.at(i).x())
			if (mBodPart.at(0).y() == mBodPart.at(i).y())
				//le Game over aura lieu
				return true;
	}
	return false;
}

bool Snake::checkCollisionWall() {
	if (mBodPart.front().x() == 5 || mBodPart.front().y() == 5 || mBodPart.front().y() == 95|| mBodPart.front().x() == 95) {
		return true;
	}
	return false;
}
void Snake::speed(float speedModifier) 
{
	mSpeed *= speedModifier;
}

void Snake::setCurDirection(Direction direction)
{
	mCurDirection = direction;
}

Snake::Direction& Snake::curDirection()
{
	return mCurDirection;
}

int Snake::bodLength()
{
	return mBodLength;
}

std::vector<Point> Snake::bodPart()
{
	return mBodPart;
}

void Snake::slitherHead()
{
	nextPoint(mBodPart.front());
}

void Snake::nextPoint(Point &point) 
{
	//Un point à additionner pour le déplacement
	if (mCurDirection == Direction::Up)
		point.setY((int)point.y()-1);
	else if (mCurDirection == Direction::Down)
		point.setY((int)point.y() + 1);
	else if (mCurDirection == Direction::Left)
		point.setX((int)point.x() - 1);
	else
		point.setX((int)point.x() + 1);
}
