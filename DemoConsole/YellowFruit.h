#ifndef YELLOWFRUIT_H
#define YELLOWFRUIT_H

#include "Fruit.h"

class YellowFruit : public Fruit
{
	float mSpeedReducor;
public:
	inline static int sCountFruit = 0;
	YellowFruit();
	YellowFruit(float speedReducor);
	YellowFruit(Point &p, int pointVal, float speedReducor, FruitType c);
	~YellowFruit();
	float getSpeedReducer();
	void beEaten(Snake *snake) override;
};


#endif //YELLOWFRUIT_H

