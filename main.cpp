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

	ConsoleButtonList cButtonList;
	cButtonList.AddButton(*(new ConsoleButton("Button1", []()
		{
			Cursor.setPosition(15, 2);
			Character.setBackColor(red + light);
			Character.setForeColor(green + light);
			std::cout << "Buttom1~";
		}
	)), 4, 8);
	ConsoleButton Button2("Button2");
	Button2.setPosition(4, 10);
	Button2.setAvailable(false);
	cButtonList.AddButton(Button2,Button2.getPosition());
	cButtonList.AddButton(*(new ConsoleButton("Button3")), 4, 12);
	cButtonList.AddButton(*(new ConsoleButton("Exit", []()
		{
			exit(0);
		}
	)), 4, 14);

	while (true) {
		cButtonList.UpdateButtonState().Render();
	}


	return 0;
}