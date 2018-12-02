#include "GameArea.h"
#include "GameSinglePlayer.h"
#include "GameMultiPlayer.h"
GameArea::GameArea()
{
}


GameArea::~GameArea()
{
}

void showInfo(ConsoleImage& image, int place, std::string type,std::string game_tag, int points,int lenght, int redFruit, int yellowFruit, int greenFruit) {
	image.drawText(place, 5, type, ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 8, "Game tag : ", ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 11, "Points : ", ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 14, "Snake Length: ", ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 17, "Red Fruit : ", ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 20, "Yellow Fruit : ", ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place, 23, "Green Fruit : ", ConsoleColor::bw + ConsoleColor::tk);

	image.drawText(place+20, 8, game_tag, ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place + 20, 11,std::to_string(points), ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place + 20, 14, std::to_string(lenght), ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place + 20, 17, std::to_string(redFruit), ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place + 20, 20, std::to_string(yellowFruit), ConsoleColor::bw + ConsoleColor::tk);
	image.drawText(place + 20, 23, std::to_string(greenFruit), ConsoleColor::bw + ConsoleColor::tk);
}

bool GameArea::singleplayer() {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & singlePlayerArea{writer.createImage("singleplayer")};
	writer.push("singleplayer");

	singlePlayerArea.fill(178, ConsoleColor::bK + ConsoleColor::tC);
	singlePlayerArea.fill(5.0, 5.0, 90.0, 90.0, (char)176, ConsoleColor::bg + ConsoleColor::tw);

	int sizeSnake = GameSinglePlayer::getInstance().snake().bodLength();

	showInfo(singlePlayerArea, 100, "singleplayer","Ludovic", 0, sizeSnake, 0, 0, 0);
	GameSinglePlayer::getInstance().showFruit(singlePlayerArea);
	GameSinglePlayer::getInstance().showSnake(singlePlayerArea);
	return false;
}

bool GameArea::multiplayer() {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & multiPlayerArea{ writer.createImage("multiplayer") };
	writer.push("multiplayer");

	multiPlayerArea.fill(178, ConsoleColor::bK + ConsoleColor::tC);
	multiPlayerArea.fill(5.0, 5.0, 90.0, 90.0, (char)176, ConsoleColor::bg + ConsoleColor::tw);

	showInfo(multiPlayerArea, 100, "multiplayer", "Ludovic", 0, 4, 0, 0, 0);
	GameMultiPlayer::getInstance().showFruit(multiPlayerArea);
	GameMultiPlayer::getInstance().showSnake(multiPlayerArea);
	return false;
}
bool GameArea::plateformer() {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & plateformerArea{ writer.createImage("plateformer") };
	writer.push("plateformer");

	plateformerArea.fill(178, ConsoleColor::bK + ConsoleColor::tC);
	plateformerArea.fill(5.0, 0.0, 90.0, 100.0, (char)176, ConsoleColor::bg + ConsoleColor::tw);

	showInfo(plateformerArea, 100, "plateformer", "Ludovic", 0, 4, 0, 0, 0);
	GameSinglePlayer::getInstance().showFruit(plateformerArea);
	GameSinglePlayer::getInstance().showSnake(plateformerArea);
	return false;
}
bool GameArea::gameModeChooser(int pos) {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & gameModeChooserArea{ writer.createImage("GameMode") };
	writer.push("GameMode");
	gameModeChooserArea.fill(178, ConsoleColor::bw + ConsoleColor::tk);
	gameModeChooserArea.drawText(30, 10, "Choose your Game Mode :", ConsoleColor::bw + ConsoleColor::tk);
	gameModeChooserArea.drawText(30, 15, "SinglePlayer", ConsoleColor::bw + ConsoleColor::tk);
	gameModeChooserArea.drawText(30, 20 , "Multiplayer ", ConsoleColor::bw + ConsoleColor::tk);
	gameModeChooserArea.drawText(30, 25, "Plateformer", ConsoleColor::bw + ConsoleColor::tk);

	//draw arrow
	gameModeChooserArea.drawText(26, 10+(pos*5),"-->", ConsoleColor::bw + ConsoleColor::tk);
	return true;
}
bool GameArea::gameOverMenu() {

	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & gameoverArea{ writer.createImage("GameOver") };
	writer.push("GameOver");

	gameoverArea.drawText(50, 20, "#####     #    #     # ####### ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 21, "#     #   # #   ##   ## #      ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 22, "#        #   #  # # # # #      ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 23, "#  #### #     # #  #  # #####  ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 24, "#     # ####### #     # #      ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 25, "#     # #     # #     # #      ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 26, " #####  #     # #     # ####### ", ConsoleColor::bk + ConsoleColor::tr);

	gameoverArea.drawText(50, 30, "####### #     # ####### ######  ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 31, "#     # #     # #       #     # ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 32, "#     # #     # #       #     # ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 33, "#     # #     # #####   ######  ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 34, "#     #  #   #  #       #   #   ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 35, "#     #   # #   #       #    #  ", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 36, "#######    #    ####### #     # ", ConsoleColor::bk + ConsoleColor::tr);

	gameoverArea.drawText(50, 45, "Press Any Key to Restart", ConsoleColor::bk + ConsoleColor::tw);

	return false;
}
bool GameArea::newGameMenu(std::string name) {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & gameoverArea{ writer.createImage("GameOver") };
	writer.push("GameOver");

	gameoverArea.drawText(50, 20, "Entrez-votre nom :", ConsoleColor::bk + ConsoleColor::tr);
	gameoverArea.drawText(50, 25, name, ConsoleColor::bk + ConsoleColor::tr);
	return false;
	
}
bool GameArea::optionMenu() {
	return true;
}
bool GameArea::welcomeMenu() {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & welcomeArea{ writer.createImage("Welcome") };
	writer.push("Welcome");

	welcomeArea.fill(178, ConsoleColor::bK + ConsoleColor::tG);
	welcomeArea.drawText(50, 20, ".----------------. .---------------- - ..----------------. .----------------. .----------------.", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 21, "| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 22, "| |    _______   | | | ____  _____  | | |      __      | | |  ___  ____   | | |  _________   | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 23, "| |   /  ___  |  | | ||_   \ |  _|   | | |	   /  \     | | | |_ || _  _|  | | | |_   ___  |  | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 24, "| |  |  (__ \_|   | | |  |   \ | |    | | |    / /\ \    | | |   | |_/ /    | | |   | |_  \_|  | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 25, "| |   '.___`-.   | | |  | |\ \|  |    | | |   / ____\   | | |   |  __'.    | | |   |  _ | _   | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 26, "| |  |`\____) |   | | | _| |_\   |_   | | | _/ /    \ \_ | | |  _| |  \ \_  | | |  _| |___/ |  | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 27, "| |  |_______.'  | | ||_____|\____|  | | ||____|  |____|| | | |____||____| | | | |_________|  | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 28, "| |              | | |              | | |              | | |              | | |              | |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 29, "| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |", ConsoleColor::br + ConsoleColor::tk);
	welcomeArea.drawText(50, 20, "'----------------' '----------------' '----------------' '----------------' '----------------'", ConsoleColor::br + ConsoleColor::tk);

	welcomeArea.drawText(75, 65, "Press any key to start",ConsoleColor::bK + ConsoleColor::tw);
	return true;
}
