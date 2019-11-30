#include "ConsoleButton.h"
using namespace ConsoleEngine;

ConsoleButton::ConsoleButton(const std::string Text)
	: ConsoleText(Text)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, const ConsolePoint2D Position)
	: ConsoleText(Text, Position)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, const int x, const int y)
	: ConsoleText(Text, x, y)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, void(*ActivateFunction)())
	: ConsoleText(Text)
	, activateFunction(ActivateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& button2)
	: ConsoleText(button2)
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
	: ConsoleText(button2)
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
	ConsoleText::operator=(button2);
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

ConsoleButton* ConsoleEngine::ConsoleButton::GetClone() const
{
	ConsoleButton* clone = new ConsoleButton(*this);
	return clone;
}

const bool ConsoleButton::CatchMouse()
{
	catchMouse = (Mouse.GetPosition().Y == position.GetY() && Mouse.GetPosition().X >= position.GetX() && Mouse.GetPosition().X <= (position.GetX() + text.length()));
	return catchMouse;
}

ConsoleButton& ConsoleButton::SetDefaultBackColor(int Color)
{
	defaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetDefaultForeColor(int Color)
{
	defaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetInactiveBackColor(int Color)
{
	inactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetInactiveForeColor(int Color)
{
	inactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetActiveBackColor(int Color)
{
	activeBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetActiveForeColor(int Color)
{
	activeForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultBackColor(int Color)
{
	unavailableDefaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultForeColor(int Color)
{
	unavailableDefaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveBackColor(int Color)
{
	unavailableInactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveForeColor(int Color)
{
	unavailableInactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetAvailable(const bool Usable)
{
	available = Usable;
	return*this;
}

ConsoleButton& ConsoleButton::SetActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const ConsoleButton& ConsoleButton::UpdateState()
{
	if (available) {
		if (catchMouse) {
			if (Mouse.GetLeftDown()) {
				backColor = activeBackColor;
				foreColor = activeForeColor;
				active = true;
				activateFunction();
			}
			else {
				backColor = inactiveBackColor;
				foreColor = inactiveForeColor;
				active = false;
			}
		}
		else {
			backColor = defaultBackColor;
			foreColor = defaultForeColor;
		}
	}
	else {
		if (catchMouse) {
			backColor = unavailableInactiveBackColor;
			foreColor = unavailableInactiveForeColor;
		}
		else {
			backColor = unavailableDefaultBackColor;
			foreColor = unavailableDefaultForeColor;
		}
	}

	CatchMouse();

	return*this;
}
