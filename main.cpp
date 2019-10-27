#include "ConsoleHeader.h"
#include <vector>
#include <string>

int main() {
	Screen.setTitle(" Game Test ");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	Cursor.hide();

	ConsoleScene cScene;

	ConsoleText cText("Game Play");
	cText.setPosition(0, 2);
	cText.setRenderMode(HorizontallyCentered);
	cText.setPosition(0, 3);
	cScene.addObject(&cText);

	ConsoleButton cButton("Button", []()
		{
			ConsoleText Text("Activate~");
			Text.setPosition(4, 12);
			Text.setRenderMode(HorizontallyCentered).render();
		}
	);
	cButton.setDefaultBackColor(green);
	cButton.setDefaultForeColor(green + light);
	cButton.setInactiveBackColor(yellow);
	cButton.setInactiveForeColor(yellow + light);
	cButton.setActiveBackColor(purple);
	cButton.setActiveForeColor(purple + light);
	cButton.setPosition(4, 12);
	cScene.addObject(&cButton);

	std::vector<std::string> image =
	{
		"$$I$$",
		"$o$o$",
		"YYYYY"
	};
	ConsoleImage cImage(image);
	cImage.setPosition(20, 20);
	cScene.addObject(&cImage);

	while (true)
		cScene.updateState().render();
	getchar();
	return 0;
}