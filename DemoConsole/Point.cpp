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