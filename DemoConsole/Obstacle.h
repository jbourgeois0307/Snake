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

private :
	double mX;
	double mY;
	size_t mSize;
};

