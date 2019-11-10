#include "ConsoleButton.h"
using namespace ConsoleEngine;

ConsoleButton::ConsoleButton(const std::string Text)
	: ConsoleObject(Text)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, const ConsolePoint2D Position)
	: ConsoleObject(Text, Position)
{
}

ConsoleButton::ConsoleButton(const std::string Text, const int x, const int y)
	: ConsoleObject(Text, x, y)
{
}

ConsoleButton::ConsoleButton(const std::string Text, void(*ActivateFunction)())
	: ConsoleObject(Text)
	, activateFunction(ActivateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& button2)
	: ConsoleObject(button2)
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
	, catchMouse(button2.catchMouse)
	, active(button2.active)
	, available(button2.available)
	, activateFunction(button2.activateFunction)
{
}

ConsoleButton::ConsoleButton(ConsoleButton&& button2)
	: ConsoleObject(button2)
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
	, catchMouse(button2.catchMouse)
	, active(button2.active)
	, available(button2.available)
	, activateFunction(button2.activateFunction)
{
	button2.~ConsoleButton();
}

const ConsoleButton& ConsoleButton::operator=(const ConsoleButton& button2)
{
	if (this == &button2)
		return*this;
	ConsoleObject::operator=(button2);
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

	catchMouse = button2.catchMouse;
	active = button2.active;
	available = button2.available;

	activateFunction = button2.activateFunction;

	return*this;
}

ConsoleButton* ConsoleEngine::ConsoleButton::getClone() const
{
	ConsoleButton* clone = new ConsoleButton(*this);
	return clone;
}

const bool ConsoleButton::CatchMouse()
{
	catchMouse = (Mouse.getPosition().Y == position.getY() && Mouse.getPosition().X >= position.getX() && Mouse.getPosition().X <= (position.getX() + text.length()));
	return catchMouse;
}

ConsoleButton& ConsoleButton::setDefaultBackColor(int Color)
{
	defaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setDefaultForeColor(int Color)
{
	defaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setInactiveBackColor(int Color)
{
	inactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setInactiveForeColor(int Color)
{
	inactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setActiveBackColor(int Color)
{
	activeBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setActiveForeColor(int Color)
{
	activeForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setUnavailableDefaultBackColor(int Color)
{
	unavailableDefaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setUnavailableDefaultForeColor(int Color)
{
	unavailableDefaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setUnavailableInactiveBackColor(int Color)
{
	unavailableInactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setUnavailableInactiveForeColor(int Color)
{
	unavailableInactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::setAvailable(const bool Usable)
{
	available = Usable;
	return*this;
}

ConsoleButton& ConsoleButton::setActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const ConsoleButton& ConsoleButton::updateState()
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

	return*this;
}

const ConsoleButton& ConsoleButton::render() const
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

	Character.setBackColor(currentBackColor);
	Character.setForeColor(currentForeColor);
	ConsoleObject::render();
	return*this;
}
