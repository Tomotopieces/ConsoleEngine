#include <iostream>
#include "ConsoleObject.h"
using namespace console_engine;
using namespace consolr_controller;

int console_engine::Rand()
{
    static bool Seed = false;
    if (!Seed) {
        Seed = true;
        srand((unsigned)time(NULL));
    }
    return rand();
}

ConsoleObject::ConsoleObject(const std::string text)
    : _text(text)
    , _position(0,0)
{
}

ConsoleObject::ConsoleObject(
    const std::string text,
    const ConsolePoint2D& position
)
    : _text(text)
    , _position(position)
{
}

ConsoleObject::ConsoleObject(
    const std::string text,
    const int x,
    const int y
)
    : _text(text)
    , _position(x, y)
{
}

ConsoleObject::ConsoleObject(const ConsoleObject& object)
    : _text(object._text)
    , _position(object._position)
{
}

ConsoleObject::ConsoleObject(ConsoleObject&& object)
    : _text(object._text)
    , _position(object._position)
{
    object.~ConsoleObject();
}

const ConsoleObject& ConsoleObject::operator=(const ConsoleObject& object)
{
    if (this == &object)
        return*this;
    _text = object._text;
    _position = object._position;
    return*this;
}

ConsoleObject* console_engine::ConsoleObject::GetClone() const
{
    ConsoleObject* temp = new ConsoleObject(*this);
    return temp;
}

const std::string ConsoleObject::GetText() const
{
    return _text;
}

const ConsolePoint2D ConsoleObject::GetPosition() const
{
    return _position;
}

ConsoleObject& ConsoleObject::SetText(const std::string text)
{
    _text = text;
    return*this;
}

ConsoleObject& ConsoleObject::SetPosition(const ConsolePoint2D position)
{
    _position = position;
    return*this;
}

ConsoleObject& ConsoleObject::SetPosition(const int x, const int y)
{
    _position = ConsolePoint2D(x, y);
    return*this;
}

const ConsoleObject& ConsoleObject::Render() const
{
    Cursor.SetPosition(_position);
    std::cout << _text;
    return*this;
}
