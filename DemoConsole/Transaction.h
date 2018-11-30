#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
private:
	Transaction();
	~Transaction();
public:
	static Transaction& getInstance()
	{
		static Transaction instance;
		return instance;
	}
private:
	bool conditionStartMenu();
	bool conditionGameModeChooser();
	bool conditionOptions();
	bool conditionWelcome();
	bool conditionSinglePlayer();
	bool conditionMultiPlayer();
	bool conditionPlatformer();
	bool conditionGameOver();
};





#endif //TRANSACTION_H
