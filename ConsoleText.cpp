#include <iostream>
#include "ConsoleText.h"
using namespace console_engine;
using namespace consolr_controller;

ConsoleText::ConsoleText(const std::string text)
    : ConsoleObject(text)
{
}

ConsoleText::ConsoleText(const std::string text, const ConsolePoint2D position)
    : ConsoleObject(text, position)
{
}

ConsoleText::ConsoleText(const std::string text, const int x, const int y)
    : ConsoleObject(text, x, y)
{
}

ConsoleText::ConsoleText(const ConsoleText& text)
    : ConsoleObject(text)
    , _backColor(text._backColor)
    , _foreColor(text._foreColor)
    , _currentMode(text._currentMode)
{
}

ConsoleText::ConsoleText(ConsoleText&& text)
    : ConsoleObject(text)
    , _backColor(text._backColor)
    , _foreColor(text._foreColor)
    , _currentMode(text._currentMode)
{
    text.~ConsoleText();
}

const ConsoleText& ConsoleText::operator=(const ConsoleText& text)
{
    if (this == &text)
        return*this;
    ConsoleObject::operator=(text);
    _backColor = text._backColor;
    _foreColor = text._foreColor;
    _currentMode = text._currentMode;
    return*this;
}

const ConsoleText& ConsoleText::operator=(const std::string& text)
{
    SetText(text);
    return*this;
}

ConsoleText* console_engine::ConsoleText::GetClone() const
{
    ConsoleText* clone = new ConsoleText(*this);
    return clone;
}

const int ConsoleText::GetBackColor() const
{
    return _backColor;
}

const int ConsoleText::GetForeColor() const
{
    return _foreColor;
}

ConsoleText& ConsoleText::SetBackColor(const int color)
{
    _backColor = color;
    return*this;
}

ConsoleText& ConsoleText::SetForeColor(const int color)
{
    _foreColor = color;
    return*this;
}

ConsoleText& ConsoleText::SetRenderMode(const RenderMode mode)
{
    _currentMode = mode;
    return*this;
}

const ConsoleText& ConsoleText::Render() const
{
    Character.SetBackColor(_backColor);
    Character.SetForeColor(_foreColor);
    
    switch (_currentMode) {
        case RenderMode::Normal:
            Cursor.SetPosition(GetPosition());
            break;
        case RenderMode::HorizontallyCentered:
            Cursor.SetPosition(
                (Screen.GetSize().X - GetText().size()) / 2,
                GetPosition().GetY()
            );
            break;
        case RenderMode::VerticallyCentered:
            Cursor.SetPosition(
                GetPosition().GetX(),
                Screen.GetSize().Y / 2
            );
            break;
        case RenderMode::CompletelyCentered:
            Cursor.SetPosition(
                (Screen.GetSize().X - GetText().size()) / 2,
                Screen.GetSize().Y / 2
            );
            break;
        case RenderMode::PointCentered:
            Cursor.SetPosition(
                GetPosition().GetX() - GetText().size() / 2,
                GetPosition().GetY()
            );
            break;
    }

    std::cout << GetText();
    return*this;
}
