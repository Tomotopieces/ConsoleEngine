#include "ConsoleObject.h"
#include <iostream>
using namespace ConsoleEngine;
using namespace ConsoleController;

int ConsoleEngine::Rand()
{
	static bool Seed = false;
	if (!Seed) {
		Seed = true;
		srand((unsigned)time(NULL));
	}
	return rand();
}

ConsoleObject::ConsoleObject(const std::string Text)
	: text(Text)
	, position(0,0)
{
}

ConsoleObject::ConsoleObject(const std::string Text, const ConsolePoint2D Position)
	: text(Text)
	, position(Position)
{
}

ConsoleObject::ConsoleObject(const std::string Text, const int x, const int y)
	: text(Text)
	, position(x, y)
{
}

ConsoleObject::ConsoleObject(const ConsoleObject& object2)
	: text(object2.text)
	, position(object2.position)
{
}

ConsoleObject::ConsoleObject(ConsoleObject&& object2)
	: text(object2.text)
	, position(object2.position)
{
	object2.~ConsoleObject();
}

const ConsoleObject& ConsoleObject::operator=(const ConsoleObject& object2)
{
	if (this == &object2)
		return*this;
	text = object2.text;
	position = object2.position;
	return*this;
}

ConsoleObject* ConsoleEngine::ConsoleObject::GetClone() const
{
	ConsoleObject* temp = new ConsoleObject(*this);
	return temp;
}

const std::string ConsoleObject::GetText() const
{
	return text;
}

const ConsolePoint2D ConsoleObject::GetPosition() const
{
	return position;
}

ConsoleObject& ConsoleObject::SetText(const std::string Text)
{
	text = Text;
	return*this;
}

ConsoleObject& ConsoleObject::SetPosition(const ConsolePoint2D position2)
{
	position = position2;
	return*this;
}

ConsoleObject& ConsoleObject::SetPosition(const int x, const int y)
{
	position = ConsolePoint2D(x, y);
	return*this;
}

const ConsoleObject& ConsoleObject::Render() const
{
	Cursor.SetPosition(position);
	std::cout << text;
	return*this;
}
