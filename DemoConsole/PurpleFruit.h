#ifndef PURPLEFRUIT_H
#define PURPLEFRUIT_H

#include "Fruit.h"

class PurpleFruit : public Fruit
{
	//A une valeur n�gative
	int mPointPenalty;
public:
	PurpleFruit();
	PurpleFruit(Point &p, int pointVal, FruitType c);
	~PurpleFruit();
	int getPointPenaltyVal();
	void beEaten(Snake *snake) override;
};

#endif // PURPLEFRUIT_H

