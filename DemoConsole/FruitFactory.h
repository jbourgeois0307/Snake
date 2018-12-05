#ifndef FRUIT_FACTORY_H
#define FRUIT_FACTORY_H

#include "Fruit.h"
class FruitFactory
{
public:
	enum class FruitType { Red, Purple, Yellow, Green};
	Fruit *createFruit();
};

#endif // !FRUIT_FACTORY_H

