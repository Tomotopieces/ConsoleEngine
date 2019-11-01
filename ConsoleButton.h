#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	using namespace ConsoleController;
	class ConsoleButton
		: public ConsoleObject
	{
	private:
		//	color
		int defaultBackColor = light;
		int defaultForeColor = black;
		int inactiveBackColor = white;			//getMouse without get leftDown
		int inactiveForeColor = black;
		int activeBackColor = white + light;
		int activeForeColor = black;
		int unavailableDefaultBackColor = red;
		int unavailableDefaultForeColor = black;
		int unavailableInactiveBackColor = red + light;
		int unavailableInactiveForeColor = black;

		//	state
		bool catchMouse = false;
		bool available = true;
		bool active = false;

		//	action
		void(*activateFunction)();

		//	others
		const bool CatchMouse();

		explicit ConsoleButton();
	public:
		//	constructor
		ConsoleButton(const std::string Text);
		ConsoleButton(const std::string Text, const ConsolePoint2D Position);
		ConsoleButton(const std::string Text, const int x, const int y);
		ConsoleButton(const std::string Text, void(*ActivateFunction)());
		ConsoleButton(const ConsoleButton& option2);
		ConsoleButton(ConsoleButton&& option2);
		const ConsoleButton& operator=(const ConsoleButton& option2);

		//	set color
		ConsoleButton& setDefaultBackColor(int Color);
		ConsoleButton& setDefaultForeColor(int Color);
		ConsoleButton& setInactiveBackColor(int Color);
		ConsoleButton& setInactiveForeColor(int Color);
		ConsoleButton& setActiveBackColor(int Color);
		ConsoleButton& setActiveForeColor(int Color);
		ConsoleButton& setUnavailableDefaultBackColor(int Color);
		ConsoleButton& setUnavailableDefaultForeColor(int Color);
		ConsoleButton& setUnavailableInactiveBackColor(int Color);
		ConsoleButton& setUnavailableInactiveForeColor(int Color);

		//	set state
		ConsoleButton& setAvailable(const bool Usable);
		ConsoleButton& setActivateFunction(void(*ActivateFunction)());

		//	others
		const ConsoleButton& updateState();
		const ConsoleButton& render()const;
	};
}