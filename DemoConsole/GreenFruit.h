#ifndef GREENFRUIT_H
#define GREENFRUIT_H

#include "Fruit.h"

class GreenFruit : public Fruit
{
	float mSpeedAmplifier;
public:
	GreenFruit();
	GreenFruit(float speedAmplifier);
	GreenFruit(Point const &p, int pointVal, float speedAmplifier);
	~GreenFruit();
	float getSpeedAmplificator();
	void beEaten(Snake * snake) override;
};


#endif //GREENFRUIT_H
