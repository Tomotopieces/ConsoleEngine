#include "ConsoleText.h"
#include <iostream>
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

ConsoleText::ConsoleText(const ConsoleText& text2)
	: ConsoleObject(text2)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
	, currentMode(text2.currentMode)
{
}

ConsoleText::ConsoleText(ConsoleText&& text2)
	: ConsoleObject(text2)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
	, currentMode(text2.currentMode)
{
	text2.~ConsoleText();
}

const ConsoleText& ConsoleText::operator=(const ConsoleText& text2)
{
	if (this == &text2)
		return*this;
	ConsoleObject::operator=(text2);
	backColor = text2.backColor;
	foreColor = text2.foreColor;
	currentMode = text2.currentMode;
	return*this;
}

const int ConsoleText::getBackColor() const
{
	return backColor;
}

const int ConsoleText::getForeColor() const
{
	return foreColor;
}

const ConsoleText& ConsoleText::setBackColor(const int color2)
{
	backColor = color2;
	return*this;
}

const ConsoleText& ConsoleText::setForeColor(const int color2)
{
	foreColor = color2;
	return*this;
}

const ConsoleText& ConsoleText::setRenderMode(const RenderMode newMode)
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
