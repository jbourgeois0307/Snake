#include "Point.h"

Point::Point()
{
}

Point::~Point()
{
}


double Point::x()
{
	return mX;
}

double Point::y()
{
	return mY;
}

Point::Point(double x, double y)
	: mX{ x },
	mY{ y }
{
}

void Point::setX(int x) 
{
	mX=x;
}

void Point::setY(int y)
{
	mY = y;
}

bool Point::operator==(Point & a)
{
	//Teste si a.m_heure == b.m_heure etc.  
	if (mX == a.x() && mY == a.y())
		return true;
	else
		return false;
}
