#include "Point.h"

class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	Obstacle(size_t size, Point p);
	double X();
	double Y();
	size_t Size();
	void setX(double x);
	void setY(double y);
private :
	double mX;
	double mY;
	size_t mSize;

};

