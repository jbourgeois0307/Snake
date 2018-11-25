#ifndef GREENFRUIT_H
#define GREENFRUIT_H

#include "Fruit.h"

class GreenFruit : public Fruit
{
	float mSpeedAmplifier;
public:
	GreenFruit();
	GreenFruit(float speedAmplifier);
	GreenFruit(int x, int y, int pointVal, float speedAmplifier);
	~GreenFruit();
	float getSpeedAmplificator();
};


#endif //GREENFRUIT_H
