#ifndef YELLOWFRUIT_H
#define YELLOWFRUIT_H

#include "Fruit.h"

class YellowFruit : public Fruit
{
	float mSpeedReducor;
public:
	YellowFruit();
	YellowFruit(float speedReducor);
	YellowFruit(int x, int y, int pointVal, float speedReducor);
	~YellowFruit();
	float getSpeedReducer();
};


#endif //YELLOWFRUIT_H
