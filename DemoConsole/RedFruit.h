#ifndef REDFRUIT_H
#define REDFRUIT_H

#include "Fruit.h"

class RedFruit : public Fruit 
{
public:
	RedFruit();
	RedFruit(int x, int y, int pointVal);
	~RedFruit();
};

#endif // !REDFRUIT_H

