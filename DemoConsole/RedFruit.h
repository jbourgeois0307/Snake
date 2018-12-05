#ifndef REDFRUIT_H
#define REDFRUIT_H

#include "Fruit.h"

class RedFruit : public Fruit 
{
public:
	RedFruit();
	RedFruit(Point const &p, int pointVal);
	~RedFruit();
	void beEaten(Snake *snake) override;
};

#endif // !REDFRUIT_H

