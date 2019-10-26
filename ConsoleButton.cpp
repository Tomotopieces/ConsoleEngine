#include "ConsoleButton.h"
#include "ConsoleFunc.h"
#include <iostream>
using namespace ConsoleFunction;

ConsoleButton::ConsoleButton(const std::string Name)
	: name(Name)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Name, void(*ActivateFunction)())
	: name(Name)
	, activateFunction(ActivateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& button2)
	: name(button2.name)
	, defaultBackColor(button2.defaultBackColor)
	, defaultForeColor(button2.defaultForeColor)
	, inactiveBackColor(button2.inactiveBackColor)
	, inactiveForeColor(button2.inactiveForeColor)
	, activeBackColor(button2.activeBackColor)
	, activeForeColor(button2.activeForeColor)
	, unavailableDefaultBackColor(button2.unavailableDefaultBackColor)
	, unavailableDefaultForeColor(button2.unavailableDefaultForeColor)
	, unavailableInactiveBackColor(button2.unavailableInactiveBackColor)
	, unavailableInactiveForeColor(button2.unavailableInactiveForeColor)
	, active(button2.active), available(button2.available)
	, activateFunction(button2.activateFunction)
	, position(button2.position)
{
}

ConsoleButton::ConsoleButton(ConsoleButton&& button2)
	: name(button2.name)
	, defaultBackColor(button2.defaultBackColor)
	, defaultForeColor(button2.defaultForeColor)
	, inactiveBackColor(button2.inactiveBackColor)
	, inactiveForeColor(button2.inactiveForeColor)
	, activeBackColor(button2.activeBackColor)
	, activeForeColor(button2.activeForeColor)
	, unavailableDefaultBackColor(button2.unavailableDefaultBackColor)
	, unavailableDefaultForeColor(button2.unavailableDefaultForeColor)
	, unavailableInactiveBackColor(button2.unavailableInactiveBackColor)
	, unavailableInactiveForeColor(button2.unavailableInactiveForeColor)
	, active(button2.active), available(button2.available)
	, activateFunction(button2.activateFunction)
	, position(button2.position)
{
	button2.~ConsoleButton();
}

const ConsoleButton& ConsoleButton::operator=(const ConsoleButton& button2)
{
	name = button2.name;
	defaultBackColor = button2.defaultBackColor;
	defaultForeColor = button2.defaultForeColor;
	inactiveBackColor = button2.inactiveBackColor;
	inactiveForeColor = button2.inactiveForeColor;
	activeBackColor = button2.activeBackColor;
	activeForeColor = button2.activeForeColor;
	unavailableDefaultBackColor = button2.unavailableDefaultBackColor;
	unavailableDefaultForeColor = button2.unavailableDefaultForeColor;
	unavailableInactiveBackColor = button2.unavailableInactiveBackColor;
	unavailableInactiveForeColor = button2.unavailableInactiveForeColor;
	active = button2.active;
	available = button2.available;

	activateFunction = button2.activateFunction;
	position = button2.position;

	return*this;
}

const bool ConsoleButton::CatchMouse()
{
	catchMouse = (Mouse.getPosition().Y == position.getY() && Mouse.getPosition().X >= position.getX() && Mouse.getPosition().X <= (position.getX() + name.length()));
	return catchMouse;
}

const std::string ConsoleButton::getName() const
{
	return name;
}

const ConsolePoint2D ConsoleButton::getPosition() const
{
	return position;
}

const ConsoleButton& ConsoleButton::setName(const std::string name2)
{
	name = name2;
	return*this;
}

const ConsoleButton& ConsoleButton::setDefaultBackColor(int color2)
{
	defaultBackColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setDefaultForeColor(int color2)
{
	defaultForeColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setInactiveBackColor(int color2)
{
	inactiveBackColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setInactiveForeColor(int color2)
{
	inactiveForeColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setActiveBackColor(int color2)
{
	activeBackColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setActiveForeColor(int color2)
{
	activeForeColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setUnavailableDefaultBackColor(int color2)
{
	unavailableDefaultBackColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setUnavailableDefaultForeColor(int color2)
{
	unavailableDefaultForeColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setUnavailableInactiveBackColor(int color2)
{
	unavailableInactiveBackColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setUnavailableInactiveForeColor(int color2)
{
	unavailableInactiveForeColor = color2;
	return*this;
}

const ConsoleButton& ConsoleButton::setAvailable(const bool Usable)
{
	available = Usable;
	return*this;
}

const ConsoleButton& ConsoleButton::setActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const ConsoleButton& ConsoleButton::setPosition(const ConsolePoint2D position2)
{
	position = position2;
	return*this;
}

const ConsoleButton& ConsoleButton::setPosition(const int x, const int y)
{
	position = ConsolePoint2D(x, y);
	return*this;
}

const bool ConsoleButton::updateState()
{
	if (catchMouse && Mouse.leftDown() && !active) {
		if (available) {
			active = true;
			activateFunction();
		}
	}
	else if(!catchMouse || !Mouse.leftDown())
		active = false;

	CatchMouse();

	return active;
}

const ConsoleButton& ConsoleButton::Render() const
{
	int currentBackColor;
	int currentForeColor;
	if (available) {
		if (catchMouse) {
			if (active) {
				currentBackColor = activeBackColor;
				currentForeColor = activeForeColor;
			}
			else {
				currentBackColor = inactiveBackColor;
				currentForeColor = inactiveForeColor;
			}
		}
		else {
			currentBackColor = defaultBackColor;
			currentForeColor = defaultForeColor;
		}
	}
	else {
		if (catchMouse) {
			currentBackColor = unavailableInactiveBackColor;
			currentForeColor = unavailableInactiveForeColor;
		}
		else {
			currentBackColor = unavailableDefaultBackColor;
			currentForeColor = unavailableDefaultForeColor;
		}
	}

	Cursor.setPosition(position);
	Character.setBackColor(currentBackColor);
	Character.setForeColor(currentForeColor);
	std::cout << name;

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

const ConsoleButtonList& ConsoleButtonList::UpdateButtonState()
{
	for (auto button = buttonList.begin(); button != buttonList.end(); ++button)
		button->updateState();
	return*this;
}
