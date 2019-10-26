#include "ConsoleFunc.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
#include <iostream>
using namespace ConsoleFunction;

int main() {
	Screen.setTitle("Game Test");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	Cursor.hide();

	ConsoleText cText("Game Play");
	cText.setPosition(0, 2);
	cText.Render(ConsoleText::HorizontallyCentered);
	cText.setPosition(0, 3);
	cText.setBackColor(light);
	cText.setForeColor(red + light);
	cText.Render(ConsoleText::HorizontallyCentered);

	ConsoleButtonList cButtonList;
	cButtonList.AddButton(*(new ConsoleButton("Normal Button", []()
		{
			ConsoleText message("Activate~");
			message.setPosition(20, 8);
			message.Render();
		}
	)), 4, 8);

	ConsoleButton Button2("Unavailable Button");
	Button2.setPosition(4, 10);
	Button2.setAvailable(false);
	cButtonList.AddButton(Button2, Button2.getPosition());

	ConsoleButton Button3("Colorful Button");
	Button3.setDefaultBackColor(green);
	Button3.setDefaultForeColor(green + light);
	Button3.setInactiveBackColor(yellow);
	Button3.setInactiveForeColor(yellow + light);
	Button3.setActiveBackColor(purple);
	Button3.setActiveForeColor(purple + light);
	cButtonList.AddButton(Button3, 4, 12);

	cButtonList.AddButton(*(new ConsoleButton("Exit", []()
		{
			ConsoleText exitText("Press any key to exit.");
			exitText.setPosition(0, 20);
			exitText.Render(ConsoleText::HorizontallyCentered);
			getchar();
			exit(0);
		}
	)), 4, 14);

	while (true)
		cButtonList.UpdateButtonState().Render();

	return 0;
}