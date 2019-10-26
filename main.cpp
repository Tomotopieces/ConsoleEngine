#include "ButtonAndList.h"
#include "ConsoleFunc.h"
#include <iostream>
using namespace ConsoleFunction;

int main() {
	Screen.setTitle("Console Shooting Game Test");
	Screen.setSize(64, 32);
	Screen.hideScrollBar();
	Cursor.hide();
	ConsoleButtonList opl;
	opl.AddButton(*(new ConsoleButton("Button1", []()
		{
			Cursor.setPosition(15, 2);
			Character.setBackColor(red + light);
			Character.setForeColor(green + light);
			std::cout << "Buttom1~";
		}
	)), 4, 2);
	opl.AddButton(*(new ConsoleButton("Button2")), 4, 4);
	opl.AddButton(*(new ConsoleButton("Button3")), 4, 6);
	opl.AddButton(*(new ConsoleButton("Exit", []()
		{
			exit(0);
		}
	)), 4, 8);

	opl.UpdateActivatedState().Render();
	getchar();
	Character.setBackColor(black);
	Character.setForeColor(light);
	std::cout << Screen.getSize().X << " " << Screen.getSize().Y;
	bool temp = Screen.clean();
	getchar();


	return 0;
}