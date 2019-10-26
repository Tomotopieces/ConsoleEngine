#include "ConsoleFunc.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
#include <iostream>
using namespace ConsoleFunction;

int main() {
	Screen.setTitle("Console Shooting Game Test");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	Cursor.hide();

	ConsoleText ctext("Game Play");
	ctext.setPosition(4, 10);
	ctext.Render();

	ConsoleButtonList cbutton;
	cbutton.AddButton(*(new ConsoleButton("Button1", []()
		{
			Cursor.setPosition(15, 2);
			Character.setBackColor(red + light);
			Character.setForeColor(green + light);
			std::cout << "Buttom1~";
		}
	)), 4, 2);
	ConsoleButton Button2("Button2");
	Button2.setPosition(4, 4);
	Button2.setAvailable(false);
	cbutton.AddButton(Button2,Button2.getPosition());
	cbutton.AddButton(*(new ConsoleButton("Button3")), 4, 6);
	cbutton.AddButton(*(new ConsoleButton("Exit", []()
		{
			exit(0);
		}
	)), 4, 8);

	while (true) {
		cbutton.UpdateButtonState().Render();
	}


	return 0;
}