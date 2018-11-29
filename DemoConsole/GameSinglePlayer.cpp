#include "GameSinglePlayer.h"
#include "Fruit.h"
#include "GameArea.h"
#include "Random.h"
#include "Point.h"
GameSinglePlayer::GameSinglePlayer() {
	haveFruit_m = false;
	Point p(0, 0);
	//fruit_m=Fruit(p,0);
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
//Point p{ Random::getInstance().bernoulliRandomize(90),Random::getInstance().bernoulliRandomize(90) };
	//fruit_m = Fruit(p, 1);
	
	haveFruit_m = true ;
}
