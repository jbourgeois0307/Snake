#include "FruitFactory.h"
#include "Random.h"
#include "GreenFruit.h"
#include "YellowFruit.h"
#include "RedFruit.h"
#include "PurpleFruit.h"

Fruit * FruitFactory::createFruit()
{
	Fruit* foo{nullptr};

	//Génère un point aléatoire
	Point p(Random::getInstance().uniformRandomize(4, 85), Random::getInstance().uniformRandomize(4, 85));
	
	//Un des types de fruit aléatoire
	FruitType f = static_cast<FruitType>(rand() % 4);
	if (f == FruitType::Green)
		foo = new GreenFruit(p,5,2.0);
	if (f == FruitType::Red)
		foo = new RedFruit(p,5);
	if (f == FruitType::Yellow)
		foo = new YellowFruit(p,5,0.5);
	if (f == FruitType::Purple)
		foo = new PurpleFruit(p,1);

	return foo;
}
