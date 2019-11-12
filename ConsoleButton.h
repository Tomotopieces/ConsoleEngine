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
		virtual const ConsoleButton& operator=(const ConsoleButton& option2);

		//	get
		virtual ConsoleButton* GetClone()const override;

		//	set color
		ConsoleButton& SetDefaultBackColor(int Color);
		ConsoleButton& SetDefaultForeColor(int Color);
		ConsoleButton& SetInactiveBackColor(int Color);
		ConsoleButton& SetInactiveForeColor(int Color);
		ConsoleButton& SetActiveBackColor(int Color);
		ConsoleButton& SetActiveForeColor(int Color);
		ConsoleButton& SetUnavailableDefaultBackColor(int Color);
		ConsoleButton& SetUnavailableDefaultForeColor(int Color);
		ConsoleButton& SetUnavailableInactiveBackColor(int Color);
		ConsoleButton& SetUnavailableInactiveForeColor(int Color);

		//	set state
		ConsoleButton& SetAvailable(const bool Usable);
		ConsoleButton& SetActivateFunction(void(*ActivateFunction)());

		//	others
		const ConsoleButton& UpdateState();
		const ConsoleButton& Render()const override;
	};
}