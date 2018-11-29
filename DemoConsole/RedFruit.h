#ifndef REDFRUIT_H
#define REDFRUIT_H

#include "Fruit.h"

class RedFruit : public Fruit 
{
public:
	RedFruit();
	RedFruit(Point &p, int pointVal);
	~RedFruit();
};

#endif // !REDFRUIT_H

