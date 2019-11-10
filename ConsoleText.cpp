#include "ConsoleText.h"
#include <iostream>
using namespace ConsoleEngine;
using namespace ConsoleController;

ConsoleText::ConsoleText(const std::string Text)
	: ConsoleObject(Text)
{
}

ConsoleText::ConsoleText(const std::string Text, const ConsolePoint2D Position)
	: ConsoleObject(Text, Position)
{
}

ConsoleText::ConsoleText(const std::string Text, const int x, const int y)
	: ConsoleObject(Text, x, y)
{
}

ConsoleText::ConsoleText(const ConsoleText& Text)
	: ConsoleObject(Text)
	, backColor(Text.backColor)
	, foreColor(Text.foreColor)
	, currentMode(Text.currentMode)
{
}

ConsoleText::ConsoleText(ConsoleText&& Text)
	: ConsoleObject(Text)
	, backColor(Text.backColor)
	, foreColor(Text.foreColor)
	, currentMode(Text.currentMode)
{
	Text.~ConsoleText();
}

const ConsoleText& ConsoleText::operator=(const ConsoleText& Text)
{
	if (this == &Text)
		return*this;
	ConsoleObject::operator=(Text);
	backColor = Text.backColor;
	foreColor = Text.foreColor;
	currentMode = Text.currentMode;
	return*this;
}

ConsoleText* ConsoleEngine::ConsoleText::getClone() const
{
	ConsoleText* clone = new ConsoleText(*this);
	return clone;
}

const int ConsoleText::getBackColor() const
{
	return backColor;
}

const int ConsoleText::getForeColor() const
{
	return foreColor;
}

ConsoleText& ConsoleText::setBackColor(const int Color)
{
	backColor = Color;
	return*this;
}

ConsoleText& ConsoleText::setForeColor(const int Color)
{
	foreColor = Color;
	return*this;
}

ConsoleText& ConsoleText::setRenderMode(const RenderMode newMode)
{
	currentMode = newMode;
	return*this;
}

const ConsoleText& ConsoleText::render() const
{
	Character.setBackColor(backColor);
	Character.setForeColor(foreColor);
	
	switch (currentMode) {
		case Normal:
			Cursor.setPosition(position);
			break;
		case HorizontallyCentered:
			Cursor.setPosition((Screen.getSize().X - text.size()) / 2, position.getY());
			break;
		case VerticallyCentered:
			Cursor.setPosition(position.getX(), Screen.getSize().Y / 2);
			break;
		case HorizontallyCentered + VerticallyCentered:
			Cursor.setPosition((Screen.getSize().X - text.size()) / 2, Screen.getSize().Y / 2);
			break;
	}

	std::cout << text;
	return*this;
}
