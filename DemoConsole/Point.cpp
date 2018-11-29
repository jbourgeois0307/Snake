#include "Point.h"

Point::Point()
{
}

Point::~Point()
{
}


int Point::x()
{
	return mX;
}

int Point::y()
{
	return mY;
}

Point::Point(int x, int y)
	: mX{ x },
	  mY{ y }
{
}