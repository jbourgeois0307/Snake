#include "GameArea.h"

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

	showInfo(singlePlayerArea, 100, "singleplayer","Ludovic", 0, 4, 0, 0, 0);
	

	return false;
}

bool GameArea::multiplayer(ConsoleKeyReader::KeyEvents& keyEvents) {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & multiPlayerArea{ writer.createImage("multiplayer") };
	writer.push("multiplayer");

	multiPlayerArea.fill(178, ConsoleColor::bK + ConsoleColor::tC);
	multiPlayerArea.fill(5.0, 5.0, 90.0, 90.0, (char)176, ConsoleColor::bR + ConsoleColor::tw);

	showInfo(multiPlayerArea, 100, "multiplayer", "Ludovic", 0, 4, 0, 0, 0);
	showInfo(multiPlayerArea, 150, "", "Joé", 0, 4, 0, 0, 0);

	return false;
}
bool GameArea::plateformer(ConsoleKeyReader::KeyEvents& keyEvents) {
	ConsoleWriter & writer{ Console::getInstance().writer() };
	ConsoleImage & plateformerArea{ writer.createImage("plateformer") };
	writer.push("plateformer");

	plateformerArea.fill(178, ConsoleColor::bK + ConsoleColor::tC);
	plateformerArea.fill(5.0, 0.0, 90.0, 100.0, (char)176, ConsoleColor::bk + ConsoleColor::tw);

	showInfo(plateformerArea, 100, "plateformer", "Ludovic", 0, 4, 0, 0, 0);
	return false;
}
bool GameArea::gameModeChooser(ConsoleKeyReader::KeyEvents& keyEvents) {
	return true;
}
bool GameArea::gameOverMenu(ConsoleKeyReader::KeyEvents& keyEvents) {
	return true;
}
bool GameArea::newGameMenu(ConsoleKeyReader::KeyEvents& keyEvents) {
	return true;
}
bool GameArea::optionMenu(ConsoleKeyReader::KeyEvents& keyEvents) {
	return true;
}
bool GameArea::welcomeMenu(ConsoleKeyReader::KeyEvents& keyEvents) {


	return true;
}

void GameArea::showFruit(Fruit f) {
	//currentImage_m.drawLine(f.getMX, f.getMY, f.getMX, f.getMY, '0', ConsoleColor::bR + ConsoleColor::tR);
}