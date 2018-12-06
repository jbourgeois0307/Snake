#ifndef GREENFRUIT_H
#define GREENFRUIT_H

#include "Fruit.h"

class GreenFruit : public Fruit
{
	float mSpeedAmplifier;
public:
	inline static int sCountFruit = 0;
	GreenFruit();
	GreenFruit(float speedAmplifier);
	GreenFruit(Point const &p, int pointVal, float speedAmplifier, FruitType c);
	~GreenFruit();
	float getSpeedAmplificator();
	void beEaten(Snake * snake) override;
};


#endif //GREENFRUIT_H
