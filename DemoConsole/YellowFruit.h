#ifndef YELLOWFRUIT_H
#define YELLOWFRUIT_H

#include "Fruit.h"

class YellowFruit : public Fruit
{
	float mSpeedReducor;
public:
	YellowFruit();
	YellowFruit(float speedReducor);
	YellowFruit(Point &p, int pointVal, float speedReducor);
	~YellowFruit();
	float getSpeedReducer();
	void beEaten(Snake *snake) override;
};


#endif //YELLOWFRUIT_H

