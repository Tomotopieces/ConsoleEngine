#pragma once
#include "Game.h"
#include <string>
#include <vector>
#include "ConsoleFunc.h"
using namespace ConsoleFunction;

class ConsoleButton {
private:
	std::string name;

	int defaultBackColor = light;
	int defaultForeColor = 0;

	int activatedBackgroundColor = white + light;
	int inactivatedBackgroundColor = light;
	int unavailableTextColor = red;


	bool activated = false;
	bool usable = true;

	void(*activateFunction)();
	ConsolePoint2D position = { 0,0 };

	explicit ConsoleButton();
public:
	ConsoleButton(const std::string Name);
	ConsoleButton(const std::string Name, void(*ActivateFunction)());
	ConsoleButton(const ConsoleButton& option2);
	ConsoleButton(ConsoleButton&& option2);
	~ConsoleButton() = default;
	const ConsoleButton& operator=(const ConsoleButton& option2);

	const std::string getName()const;
	const ConsoleButton& setName(const std::string Name);
	const ConsoleButton& setActivatedkgroundColor(const int Color);
	const ConsoleButton& setInactivatedkgroundColor(const int Color);
	const ConsoleButton& setUnavailableTextColor(const int Color);
	const ConsoleButton& setActivated(const bool Activated);
	const ConsoleButton& setUsable(const bool Usable);
	const ConsoleButton& setActivateFunction(void(*ActivateFunction)());
	const ConsoleButton& setPosition(const ConsolePoint2D Position);
	const ConsoleButton& setPosition(const int x, const int y);

	const ConsoleButton& Render()const;

	const bool catchMouse()const;
	const bool Activated();
};

class ConsoleButtonList {
private:
	std::vector<ConsoleButton> buttonList;
public:
	ConsoleButtonList();

	ConsoleButtonList& AddButton(ConsoleButton newButton, const ConsolePoint2D position);
	ConsoleButtonList& AddButton(ConsoleButton newButton, const int x, const int y);

	const ConsoleButtonList& Render()const;
	const ConsoleButtonList& UpdateActivatedState();
};