#include "ButtonAndList.h"
#include "ConsoleFunc.h"
#include <iostream>
using namespace ConsoleFunction;

ConsoleButton::ConsoleButton(const std::string Name)
	: name(Name), activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Name, void(*ActivateFunction)())
	: name(Name), activateFunction(ActivateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& button2)
	: name(button2.name), activatedBackgroundColor(button2.activatedBackgroundColor), inactivatedBackgroundColor(button2.inactivatedBackgroundColor), unavailableTextColor(button2.unavailableTextColor), activated(button2.activated), usable(button2.usable), activateFunction(button2.activateFunction), position(button2.position)
{
}

ConsoleButton::ConsoleButton(ConsoleButton&& button2)
	: name(button2.name), activatedBackgroundColor(button2.activatedBackgroundColor), inactivatedBackgroundColor(button2.inactivatedBackgroundColor), unavailableTextColor(button2.unavailableTextColor), activated(button2.activated), usable(button2.usable), activateFunction(button2.activateFunction), position(button2.position)
{
	button2.~ConsoleButton();
}

const ConsoleButton& ConsoleButton::operator=(const ConsoleButton& button2)
{
	name = button2.name;
	activatedBackgroundColor = button2.activatedBackgroundColor;
	inactivatedBackgroundColor = button2.inactivatedBackgroundColor;
	unavailableTextColor = button2.unavailableTextColor;
	activated = button2.activated;
	usable = button2.usable;

	activateFunction = button2.activateFunction;
	position = button2.position;

	return*this;
}

const std::string ConsoleButton::getName() const
{
	return name;
}

const ConsoleButton& ConsoleButton::setName(const std::string Name)
{
	name = name;
	return*this;
}

const ConsoleButton& ConsoleButton::setUnavailableTextColor(const int Color)
{
	unavailableTextColor = Color;
	return*this;
}

const ConsoleButton& ConsoleButton::setActivated(const bool Activated)
{
	activated = Activated;
	return*this;
}

const ConsoleButton& ConsoleButton::setUsable(const bool Usable)
{
	usable = Usable;
	return*this;
}

const ConsoleButton& ConsoleButton::setActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const ConsoleButton& ConsoleButton::setPosition(const ConsolePoint2D Position)
{
	position = Position;
	return*this;
}

const ConsoleButton& ConsoleButton::setPosition(const int x, const int y)
{
	position = ConsolePoint2D(x, y);
	return*this;
}

const ConsoleButton& ConsoleButton::Render() const
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

const bool ConsoleButton::catchMouse() const
{
	return Mouse.getPosition().Y == position.getY() && Mouse.getPosition().X >= position.getX() && Mouse.getPosition().X <= (position.getX() + name.length());
}

const bool ConsoleButton::Activated()
{
	if (catchMouse() && Mouse.leftDown()) {
		activated = true;
		activateFunction();
	}
	else
		activated = false;
	return activated;
}

const ConsoleButton& ConsoleButton::setActivatedkgroundColor(const int Color)
{
	activatedBackgroundColor = Color;
	return*this;
}

const ConsoleButton& ConsoleButton::setInactivatedkgroundColor(const int Color)
{
	inactivatedBackgroundColor = Color;
	return*this;
}

ConsoleButtonList::ConsoleButtonList()
{
}

ConsoleButtonList& ConsoleButtonList::AddButton(ConsoleButton newButton, const ConsolePoint2D Position)
{
	newButton.setPosition(Position);
	buttonList.push_back(newButton);
	return*this;
}

ConsoleButtonList& ConsoleButtonList::AddButton(ConsoleButton newButton, const int x, const int y)
{
	newButton.setPosition(x, y);
	buttonList.push_back(newButton);
	return*this;
}

const ConsoleButtonList& ConsoleButtonList::Render() const
{
	for (auto option = buttonList.begin(); option != buttonList.end(); ++option)
		option->Render();
	return*this;
}

const ConsoleButtonList& ConsoleButtonList::UpdateActivatedState()
{
	for (auto option = buttonList.begin(); option != buttonList.end(); ++option)
		option->Activated();
	return*this;
}
