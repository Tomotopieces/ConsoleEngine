#include "ConsoleButton.h"
using namespace console_engine;

ConsoleButton::ConsoleButton(const std::string text)
    : ConsoleText(text)
    , _activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(
    const std::string text,
    const ConsolePoint2D position
)
    : ConsoleText(text, position)
    , _activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(
    const std::string text,
    const int x,
    const int y
)
    : ConsoleText(text, x, y)
    , _activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(
    const std::string text,
    void(*activateFunction)()
)
    : ConsoleText(text)
    , _activateFunction(activateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& button)
    : ConsoleText(button)
    , _defaultBackColor(button._defaultBackColor)
    , _defaultForeColor(button._defaultForeColor)
    , _inactiveBackColor(button._inactiveBackColor)
    , _inactiveForeColor(button._inactiveForeColor)
    , _activeBackColor(button._activeBackColor)
    , _activeForeColor(button._activeForeColor)
    , _unavailableDefaultBackColor(button._unavailableDefaultBackColor)
    , _unavailableDefaultForeColor(button._unavailableDefaultForeColor)
    , _unavailableInactiveBackColor(button._unavailableInactiveBackColor)
    , _unavailableInactiveForeColor(button._unavailableInactiveForeColor)
    , _catchMouse(button._catchMouse)
    , _active(button._active)
    , _available(button._available)
    , _draggable(button._draggable)
    , _activateFunction(button._activateFunction)
{
}

ConsoleButton::ConsoleButton(ConsoleButton&& button)
    : ConsoleText(button)
    , _defaultBackColor(button._defaultBackColor)
    , _defaultForeColor(button._defaultForeColor)
    , _inactiveBackColor(button._inactiveBackColor)
    , _inactiveForeColor(button._inactiveForeColor)
    , _activeBackColor(button._activeBackColor)
    , _activeForeColor(button._activeForeColor)
    , _unavailableDefaultBackColor(button._unavailableDefaultBackColor)
    , _unavailableDefaultForeColor(button._unavailableDefaultForeColor)
    , _unavailableInactiveBackColor(button._unavailableInactiveBackColor)
    , _unavailableInactiveForeColor(button._unavailableInactiveForeColor)
    , _catchMouse(button._catchMouse)
    , _active(button._active)
    , _available(button._available)
    , _draggable(button._draggable)
    , _activateFunction(button._activateFunction)
{
    button.~ConsoleButton();
}

const ConsoleButton& ConsoleButton::operator=(const ConsoleButton& button)
{
    if (this == &button)
        return*this;
    ConsoleText::operator=(button);
    _defaultBackColor = button._defaultBackColor;
    _defaultForeColor = button._defaultForeColor;
    _inactiveBackColor = button._inactiveBackColor;
    _inactiveForeColor = button._inactiveForeColor;
    _activeBackColor = button._activeBackColor;
    _activeForeColor = button._activeForeColor;
    _unavailableDefaultBackColor = button._unavailableDefaultBackColor;
    _unavailableDefaultForeColor = button._unavailableDefaultForeColor;
    _unavailableInactiveBackColor = button._unavailableInactiveBackColor;
    _unavailableInactiveForeColor = button._unavailableInactiveForeColor;

    _catchMouse = button._catchMouse;
    _active = button._active;
    _available = button._available;
    _draggable = button._draggable;

    _activateFunction = button._activateFunction;

    return*this;
}

ConsoleButton* ConsoleButton::GetClone() const
{
    ConsoleButton* clone = new ConsoleButton(*this);
    return clone;
}

const bool ConsoleButton::IsDraggable() const
{
    return _draggable;
}

void ConsoleButton::Drag()
{
    SetPosition(Mouse.GetPosition().X - _dragOffset, Mouse.GetPosition().Y);
}

const bool ConsoleButton::CatchMouse()
{
    _catchMouse = (
        Mouse.GetPosition().Y == GetPosition().GetY() &&
        Mouse.GetPosition().X >= GetPosition().GetX() &&
        Mouse.GetPosition().X <= (GetPosition().GetX() + GetText().length())
        );
    return _catchMouse;
}

ConsoleButton& ConsoleButton::SetDefaultBackColor(int color)
{
    _defaultBackColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetDefaultForeColor(int color)
{
    _defaultForeColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetInactiveBackColor(int color)
{
    _inactiveBackColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetInactiveForeColor(int color)
{
    _inactiveForeColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetActiveBackColor(int color)
{
    _activeBackColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetActiveForeColor(int color)
{
    _activeForeColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultBackColor(int color)
{
    _unavailableDefaultBackColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultForeColor(int color)
{
    _unavailableDefaultForeColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveBackColor(int color)
{
    _unavailableInactiveBackColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveForeColor(int color)
{
    _unavailableInactiveForeColor = color;
    return*this;
}

ConsoleButton& ConsoleButton::SetAvailable(const bool available)
{
    _available = available;
    return*this;
}

ConsoleButton& ConsoleButton::SetActivateFunction(void(*activateFunction)())
{
    _activateFunction = activateFunction;
    return*this;
}

const ConsoleButton& ConsoleButton::UpdateState()
{
    if (_available) {
        if (_catchMouse) {
            if (Mouse.GetLeftDown()) {
                SetBackColor(_activeBackColor);
                SetForeColor(_activeForeColor);
                _active = true;
                if (_draggable) {
                    _dragOffset = Mouse.GetPosition().X - GetPosition().GetX();
                    Drag();
                }
                else
                    _activateFunction();
            }
            else {
                SetBackColor(_inactiveBackColor);
                SetForeColor(_inactiveForeColor);
                _active = false;
            }
        }
        else {
            SetBackColor(_defaultBackColor);
            SetForeColor(_defaultForeColor);
        }
    }
    else {
        if (_catchMouse) {
            SetBackColor(_unavailableInactiveBackColor);
            SetForeColor(_unavailableInactiveForeColor);
        }
        else {
            SetBackColor(_unavailableDefaultBackColor);
            SetForeColor(_unavailableDefaultForeColor);
        }
    }

    CatchMouse();

    return*this;
}

const ConsoleButton& ConsoleButton::SetDraggable(const bool draggable)
{
    if (_draggable == draggable)
        return*this;
    _draggable = draggable;
    return*this;
}
