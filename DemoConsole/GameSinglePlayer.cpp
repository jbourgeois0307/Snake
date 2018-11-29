#include "GameSinglePlayer.h"
#include "Fruit.h"
#include "GameArea.h"
#include <random>
GameSinglePlayer::GameSinglePlayer() {
	haveFruit_m = false;
	f = new Fruit();
}
GameSinglePlayer::~GameSinglePlayer()
{
}
bool GameSinglePlayer::play()
{
	if (haveFruit_m) {

	}
	else {
		generateFruit();
	}
	GameArea::getInstance().singleplayer();
	return false;
}
void GameSinglePlayer::generateFruit() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 3);
	int generatedFruit = distribution(generator);

	switch (generatedFruit) {
	case 1 :
		break;
	case 2 :
		break;
	case 3:
		break;
	}
	f = new Fruit();
	haveFruit_m = true ;
}
