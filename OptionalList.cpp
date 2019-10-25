#include "OptionalList.h"
#include "ConsoleFunc.h"
#include <iostream>
using namespace ConsoleFunction;

Option::Option(const std::string Name)
	: name(Name), activateFunction([]() {})
{
}

Option::Option(const std::string Name, void(*ActivateFunction)())
	: name(Name), activateFunction(ActivateFunction)
{
}

Option::Option(const Option& option2)
	: name(option2.name), activatedBackgroundColor(option2.activatedBackgroundColor), inactivatedBackgroundColor(option2.inactivatedBackgroundColor), unavailableTextColor(option2.unavailableTextColor), activated(option2.activated), usable(option2.usable), activateFunction(option2.activateFunction), position(option2.position)
{
}

Option::Option(Option&& option2)
	: name(option2.name), activatedBackgroundColor(option2.activatedBackgroundColor), inactivatedBackgroundColor(option2.inactivatedBackgroundColor), unavailableTextColor(option2.unavailableTextColor), activated(option2.activated), usable(option2.usable), activateFunction(option2.activateFunction), position(option2.position)
{
	option2.~Option();
}

const Option& Option::operator=(const Option& option2)
{
	name = option2.name;
	activatedBackgroundColor = option2.activatedBackgroundColor;
	inactivatedBackgroundColor = option2.inactivatedBackgroundColor;
	unavailableTextColor = option2.unavailableTextColor;
	activated = option2.activated;
	usable = option2.usable;

	activateFunction = option2.activateFunction;
	position = option2.position;

	return*this;
}

const std::string Option::getName() const
{
	return name;
}

const Option& Option::setName(const std::string Name)
{
	name = name;
	return*this;
}

const Option& Option::setUnavailableTextColor(const int Color)
{
	unavailableTextColor = Color;
	return*this;
}

const Option& Option::setActivated(const bool Activated)
{
	activated = Activated;
	return*this;
}

const Option& Option::setUsable(const bool Usable)
{
	usable = Usable;
	return*this;
}

const Option& Option::setActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const Option& Option::setPosition(const Point Position)
{
	position = Position;
	return*this;
}

const Option& Option::setPosition(const int x, const int y)
{
	position = Point(x, y);
	return*this;
}

const Option& Option::Render() const
{
	if (!activated)
		Character.setBackColor(inactivatedBackgroundColor);
	else
		Character.setBackColor(activatedBackgroundColor);

	if (usable)
		Character.setForeColor(0);
	else
		Character.setForeColor(unavailableTextColor);

	Cursor.setPosition(position);
	std::cout << name;

	return*this;
}

const bool Option::catchMouse() const
{
	return Mouse.getPosition().Y == position.getY() && Mouse.getPosition().X >= position.getX() && Mouse.getPosition().X <= (position.getX() + name.length());
}

const bool Option::Activated()
{
	if (catchMouse() && Mouse.leftDown()) {
		activated = true;
		activateFunction();
	}
	else
		activated = false;
	return activated;
}

const Option& Option::setActivatedkgroundColor(const int Color)
{
	activatedBackgroundColor = Color;
	return*this;
}

const Option& Option::setInactivatedkgroundColor(const int Color)
{
	inactivatedBackgroundColor = Color;
	return*this;
}

OptionList::OptionList()
{
}

OptionList& OptionList::AddOption(Option newOption, const Point Position)
{
	newOption.setPosition(Position);
	optionList.push_back(newOption);
	return*this;
}

OptionList& OptionList::AddOption(Option newOption, const int x, const int y)
{
	newOption.setPosition(x, y);
	optionList.push_back(newOption);
	return*this;
}

const OptionList& OptionList::Render() const
{
	for (auto option = optionList.begin(); option != optionList.end(); ++option)
		option->Render();
	return*this;
}

const OptionList& OptionList::UpdateActivatedState()
{
	for (auto option = optionList.begin(); option != optionList.end(); ++option)
		option->Activated();
	return*this;
}
