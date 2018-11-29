

#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
	Game::start();

	//
	//Console::defineContext(context);
	//
	//ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	//ConsoleWriter & writer{ Console::getInstance().writer() };
	//
	//
	////Filtre pour les touches du clavier pour le jeu
	//reader.installFilter(new ConsoleKeyFilterUp);
	//reader.installFilter(new ConsoleKeyFilterModifiers);
	//
	////Mettre une image à l'écran
	//writer.createImage("MonImage").fill('O', ConsoleColor::bK + ConsoleColor::tY);
	//writer.push("MonImage");
	//
	//ConsoleImage  & tonImage{ writer.createImage("TonImage") };
	//tonImage.fill(char(219), ConsoleColor::bK + ConsoleColor::tY);
	//tonImage.drawText(5,5,"Hello World!", ConsoleColor::bK + ConsoleColor::tY, true);
	//tonImage.drawText(5,5,"Jello World!", ConsoleColor::bK + ConsoleColor::tY, false);
	//
	//ConsoleImage  & autreImage{ writer.createImage("AutreImage") };
	//autreImage.fill(char(219), ConsoleColor::bK);
	//
	//ConsoleKeyReader::KeyEvents keyEvents;
	//
	//size_t slow{ 0 };
	//while (true) {
	//	for (int i{ 0 }; i < slow;++i) {
	//		for (int j{ 0 }; j < slow; ++j) {
	//			for (int k{ 0 }; k < slow; ++k) {
	//			}
	//		}
	//	}
	//	//writer.push("MonImage");
	//	writer.push("TonImage");
	//	//reader.read(keyEvents);
	//
	//	//Utile pour débugger:
	//	/*if (keyEvents.size()>0) {
	//		cout << keyEvents.front().toDebugString() << endl;
	//	}*/
	//	
	//	/*for (auto event : keyEvents) {
	//		if (event.keyV == 'Q')
	//			cout << "Q" << endl;
	//	}*/
	//	
	//	//if (keyEvents.size()>0)
	//	//	Console::getInstance().writer().randomize();
	//
	//	//Couleur de la console
	//	//ConsoleColor::tk;  
	//
	//	//Calibre autrement?
	//	//writer.calib();
	//}
	//
	return 0;
}