#ifndef REDFRUIT_H
#define REDFRUIT_H

#include "Fruit.h"

class RedFruit : public Fruit 
{
public:
	inline static int sCountFruit = 0;
	RedFruit();
	RedFruit(Point const &p, int pointVal, FruitType c);
	~RedFruit();
	void beEaten(Snake *snake) override;
};

#endif // !REDFRUIT_H

