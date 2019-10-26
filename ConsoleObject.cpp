#include "ConsoleObject.h"
#include <iostream>
using namespace ConsoleFunction;

ConsoleObject::ConsoleObject(const std::string Text)
	: text(Text)
	, position(0,0)
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
	text = object2.text;
	position = object2.position;
	return*this;
}

const std::string ConsoleObject::getText() const
{
	return text;
}

const ConsolePoint2D ConsoleObject::getPosition() const
{
	return position;
}

const ConsoleObject& ConsoleObject::setText(const std::string Text)
{
	text = Text;
	return*this;
}

const ConsoleObject& ConsoleObject::setPosition(const ConsolePoint2D position2)
{
	position = position2;
	return*this;
}

const ConsoleObject& ConsoleObject::setPosition(const int x, int y)
{
	position = ConsolePoint2D(x, y);
	return*this;
}

const ConsoleObject& ConsoleObject::render() const
{
	Cursor.setPosition(position);
	std::cout << text;
}
