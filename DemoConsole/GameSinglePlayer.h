class GameSinglePlayer
{
private:
	GameSinglePlayer();
	~GameSinglePlayer();
	bool haveFruit_m;
	Fruit f;
public:
	static GameSinglePlayer& getInstance()
	{
		static GameSinglePlayer instance;
		return instance;
	}

	bool play();
	void generateFruit();

};

