#pragma once
#include "Game.h"
#include <string>
#include <vector>
#include "ConsoleFunc.h"

class Option {
private:
	std::string name;
	int activatedBackgroundColor = ConsoleFunction::white + ConsoleFunction::light;
	int inactivatedBackgroundColor = ConsoleFunction::light;
	int unavailableTextColor = ConsoleFunction::red;
	bool activated = false;
	bool usable = true;

	void(*activateFunction)();
	Point position = { 0,0 };

	explicit Option();
public:
	Option(const std::string Name);
	Option(const std::string Name, void(*ActivateFunction)());
	Option(const Option& option2);
	Option(Option&& option2);
	~Option() = default;
	const Option& operator=(const Option& option2);

	const std::string getName()const;
	const Option& setName(const std::string Name);
	const Option& setActivatedkgroundColor(const int Color);
	const Option& setInactivatedkgroundColor(const int Color);
	const Option& setUnavailableTextColor(const int Color);
	const Option& setActivated(const bool Activated);
	const Option& setUsable(const bool Usable);
	const Option& setActivateFunction(void(*ActivateFunction)());
	const Option& setPosition(const Point Position);
	const Option& setPosition(const int x, const int y);

	const Option& Render()const;

	const bool catchMouse()const;
	const bool Activated();
};

class OptionList {
private:
	std::vector<Option> optionList;
public:
	OptionList();

	OptionList& AddOption(Option newOption, const Point position);
	OptionList& AddOption(Option newOption, const int x, const int y);

	const OptionList& Render()const;
	const OptionList& UpdateActivatedState();
};