#include "GameArea.h"
#include "Console.h"
#include "GameMultiPlayer.h"
#include "GamePlateformer.h"
#include "GameSinglePlayer.h"

GameArea::GameArea()
{
	
}


GameArea::~GameArea()
{
}
bool GameArea::singleplayer() {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	writer.createImage("singleplayerBorder").fill(178, ConsoleColor::bK + ConsoleColor::tY);
	writer.push("singleplayerBorder");
	return false;
}
bool GameArea::multiplayer() {
	return true;
}
bool GameArea::plateformer() {
	return true;
}
bool GameArea::gameModeChooser() {
	return true;
}
bool GameArea::gameOverMenu() {
	return true;
}
bool GameArea::newGameMenu() {
	return true;
}
bool GameArea::optionMenu() {
	return true;
}
bool GameArea::welcomeMenu() {
	return true;
}