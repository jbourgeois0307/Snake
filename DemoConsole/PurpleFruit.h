#ifndef PURPLEFRUIT_H
#define PURPLEFRUIT_H

#include "Fruit.h"

class PurpleFruit : public Fruit
{
	//A une valeur négative
	int mPointPenalty;
public:
	inline static int sCountFruit = 0;
	PurpleFruit();
	PurpleFruit(Point &p, int pointVal, FruitType c);
	~PurpleFruit();
	int getPointPenaltyVal();
	void beEaten(Snake *snake) override;
};

#endif // PURPLEFRUIT_H

