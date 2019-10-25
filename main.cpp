#include "OptionalList.h"
#include "ConsoleFunc.h"
#include <iostream>
using namespace ConsoleFunction;

int main() {
	Screen.setTitle("Console Shooting Game Test");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	Cursor.hide();
	OptionList opl;
	opl.AddOption(*(new Option("Button1", []()
		{
			Cursor.setPosition(15, 2);
			Character.setBackColor(red + light);
			Character.setForeColor(green + light);
			std::cout << "Buttom1~";
		}
	)), 4, 2);
	opl.AddOption(*(new Option("Button2")), 4, 4);
	opl.AddOption(*(new Option("Button3")), 4, 6);
	opl.AddOption(*(new Option("Exit", []()
		{
			exit(0);
		}
	)), 4, 8);

	while (1)
		opl.UpdateActivatedState().Render();

	return 0;
}