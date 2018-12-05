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
	Fruit::FruitType f = static_cast<Fruit::FruitType>(rand() % 4);
	if (f == Fruit::FruitType::Green)
		foo = new GreenFruit(p,5,2.0, Fruit::FruitType::Green);
	if (f == Fruit::FruitType::Red)
		foo = new RedFruit(p,5, Fruit::FruitType::Red);
	if (f == Fruit::FruitType::Yellow)
		foo = new YellowFruit(p,5,0.5, Fruit::FruitType::Yellow);
	if (f == Fruit::FruitType::Purple)
		foo = new PurpleFruit(p,1, Fruit::FruitType::Purple);

	return foo;
}
