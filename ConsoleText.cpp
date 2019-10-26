#include "ConsoleText.h"
#include <iostream>

ConsoleText::ConsoleText(const std::string Name)
	: text(Name)
{
}

ConsoleText::ConsoleText(const ConsoleText& text2)
	: text(text2.text)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
	, position(text2.position)
{
}

ConsoleText::ConsoleText(ConsoleText&& text2)
	: text(text2.text)
	, backColor(text2.backColor)
	, foreColor(text2.foreColor)
	, position(text2.position)
{
	text2.~ConsoleText();
}

const ConsoleText& ConsoleText::operator=(const ConsoleText& text2)
{
	text = text2.text;
	backColor = text2.backColor;
	foreColor = text2.foreColor;
	position = text2.position;
	return*this;
}

const std::string ConsoleText::getText() const
{
	return text;
}

const ConsolePoint2D ConsoleText::getPosition() const
{
	return position;
}

const ConsoleText& ConsoleText::setText(const std::string text2)
{
	text = text2;
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

const ConsoleText& ConsoleText::setPosition(const ConsolePoint2D position2)
{
	position = position2;
	return*this;
}

const ConsoleText& ConsoleText::setPosition(const int x, const int y)
{
	position = ConsolePoint2D(x, y);
	return*this;
}

const ConsoleText& ConsoleText::Render() const
{
	Character.setBackColor(backColor);
	Character.setForeColor(foreColor);
	Cursor.setPosition(position);
	std::cout << text;
	return*this;
}
