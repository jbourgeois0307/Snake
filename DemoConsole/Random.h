#include <random>
class Random
{
private:
	std::default_random_engine generator;
public:
	Random();
	~Random();

	int uniformRandomize(size_t min, size_t max);

	int poissonRandomize(double mean);

	int bernoulliRandomize(double proportion);
};

