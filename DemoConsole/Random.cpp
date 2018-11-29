#include "Random.h"



Random::Random()
{
}


Random::~Random()
{
}

int Random::uniformRandomize(size_t min, size_t max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

int Random::poissonRandomize(double mean)
{
	std::poisson_distribution<int> distribution(mean);
	return distribution(generator);
}

int Random::bernoulliRandomize(double proportion)
{
	std::bernoulli_distribution distribution(proportion);
	return distribution(generator);
}
