#ifndef POINT_H
#define POINT_H


class Point
{
	double mX, mY;
public:
	Point();
	Point(double x, double y);
	void setX(int x);
	void setY(int y);
	~Point();
	double x();
	double y();
	void setY();
};




#endif //POINT_H
