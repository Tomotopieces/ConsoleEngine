#include "ConsoleEngineHeader.h"
#include <string>
using namespace ConsoleEngine;
using namespace ConsoleController;

int main() {
	Screen.setTitle("Game Test");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	auto temp = Screen.setBackgroundColor(blue);
	Screen.clean();
	Cursor.hide();

	ConsoleScene cScene;

	ConsoleText cText("Game Play");
	cText.setPosition(0, 2);
	cText.setBackColor(blue);
	cText.setForeColor(white + light);
	cText.setRenderMode(HorizontallyCentered);
	cScene.addObject(&cText);

	std::vector<std::string> image =
	{
		"$$I$$",
		"$o$o$",
		"YYYYY"
	};
	ConsoleImage cImage(image);
	cImage.setAllColor(blue, cyan + light);
	cImage.setPosition(29, 20);
	cScene.addObject(&cImage);

	while (true)
		cScene.updateState().render();
	return 0;
}