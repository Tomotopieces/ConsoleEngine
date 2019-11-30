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

ConsoleText* ConsoleEngine::ConsoleText::GetClone() const
{
	ConsoleText* clone = new ConsoleText(*this);
	return clone;
}

const int ConsoleText::GetBackColor() const
{
	return backColor;
}

const int ConsoleText::GetForeColor() const
{
	return foreColor;
}

ConsoleText& ConsoleText::SetBackColor(const int Color)
{
	backColor = Color;
	return*this;
}

ConsoleText& ConsoleText::SetForeColor(const int Color)
{
	foreColor = Color;
	return*this;
}

ConsoleText& ConsoleText::SetRenderMode(const RenderMode newMode)
{
	currentMode = newMode;
	return*this;
}

const ConsoleText& ConsoleText::Render() const
{
	Character.SetBackColor(backColor);
	Character.SetForeColor(foreColor);
	
	switch (currentMode) {
		case Normal:
			Cursor.SetPosition(position);
			break;
		case HorizontallyCentered:
			Cursor.SetPosition((Screen.GetSize().X - text.size()) / 2, position.GetY());
			break;
		case VerticallyCentered:
			Cursor.SetPosition(position.GetX(), Screen.GetSize().Y / 2);
			break;
		case HorizontallyCentered + VerticallyCentered:
			Cursor.SetPosition((Screen.GetSize().X - text.size()) / 2, Screen.GetSize().Y / 2);
			break;
		case PointCentered:
			Cursor.SetPosition(GetPosition().GetX() - text.size() / 2, GetPosition().GetY());
			break;
	}

	std::cout << text;
	return*this;
}
