#include "console"
#include <iostream>
int main() {

	ConsoleContext context(200, 100, "B52", 8, 8, L"Consolas");
	//context = ConsoleContext::themeStandard();

	Console::defineContext(context);

	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
	ConsoleWriter & writer{ Console::getInstance().writer() };

	writer.createImage("MonImage").fill('*', ConsoleColor::bK + ConsoleColor::tY);
	writer.push("MonImage");

	ConsoleImage & tonImage{writer.createImage("TonImage")};
	tonImage.fill(char(219), ConsoleColor::bK + ConsoleColor::tY);

	ConsoleImage & autreImage{ writer.createImage("une autre image") };
	autreImage.fill(char(219), ConsoleColor::bK + ConsoleColor::tY);
	autreImage.drawText(5, 5, "Hello World", );
	reader.installFilter(new ConsoleKeyFilterUp);
	reader.installFilter(new ConsoleKeyFilterModifiers);


	ConsoleKeyReader::KeyEvents keyEvents;

	size_t slow{ 1000 };
	while (true) {
		for (int i{ 0 }; i < slow; i++)
			for (int j{ 0 }; j < slow; j++)
				for (int k{ 0 }; k < slow; k++);

		/*reader.read(keyEvents);
		if (keyEvents.size() > 0)
			std::cout << "\n" << keyEvents.front().toDebugString() << "\n";

		for (auto event : keyEvents) {
			if (event.keyV() == 'Q') {
				std::cout << "Quitter";
			}
		}
*/
		writer.push("MonImage");
		writer.push("TonImage");
		writer.push("une autre image");
		//writer.calib();
		/*if (keyEvents.size() > 0){
			Console::getInstance().writer().randomize();

		}*/
	}

	Console::getInstance().writer().randomize();
	return 0;
}