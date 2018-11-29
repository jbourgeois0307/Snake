#include <random>
class Random
{
private:
	std::default_random_engine generator;
	Random();
	~Random();
public:

	static Random& getInstance()
	{
		static Random instance;
		return instance;
	}

	int uniformRandomize(size_t min, size_t max);

	int poissonRandomize(double mean);

	int bernoulliRandomize(double proportion);
};

