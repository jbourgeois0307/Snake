#ifndef PURPLEFRUIT_H
#define PURPLEFRUIT_H

#include "Fruit.h"

class PurpleFruit : public Fruit
{
	//A une valeur négative
	int mPointPenalty;
public:
	PurpleFruit();
	PurpleFruit(int x, int y, int pointVal);
	~PurpleFruit();
	int getPointPenaltyVal();
};

#endif // PURPLEFRUIT_H

