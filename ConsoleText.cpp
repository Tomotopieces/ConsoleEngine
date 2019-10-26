#include "ConsoleText.h"
#include <iostream>

ConsoleText::ConsoleText(const std::string Text)
	: ConsoleObject(Text)
{
}

ConsoleText::ConsoleText(const ConsoleText& text2)
	: ConsoleObject(text2)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
{
}

ConsoleText::ConsoleText(ConsoleText&& text2)
	: ConsoleObject(text2)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
{
	text2.~ConsoleText();
}

const ConsoleText& ConsoleText::operator=(const ConsoleText& text2)
{
	ConsoleObject::operator=(text2);

	backColor = text2.backColor;
	foreColor = text2.foreColor;
	return*this;
}

const ConsoleText& ConsoleText::setBackColor(int color2)
{
	backColor = color2;
	return*this;
}

const ConsoleText& ConsoleText::setForeColor(int color2)
{
	foreColor = color2;
	return*this;
}

const ConsoleText& ConsoleText::Render(RenderMode renderMode) const
{
	Character.setBackColor(backColor);
	Character.setForeColor(foreColor);
	switch (renderMode) {
		case Normal:
			Cursor.setPosition(position);
			break;
		case HorizontallyCentered:
			Cursor.setPosition(Screen.getSize().X / 2 - text.size() / 2, position.getY());
			break;
		case VerticallyCentered:
			Cursor.setPosition(position.getX(), Screen.getSize().Y / 2);
			break;
		case HorizontallyCentered + VerticallyCentered:
			Cursor.setPosition(Screen.getSize().X / 2 - text.size() / 2, Screen.getSize().Y / 2);
			break;
	}
	std::cout << text;
	return*this;
}
