#include "ConsoleCharacter.h"
#include <iostream>

ConsoleCharacter::ConsoleCharacter(const char Character)
	: ConsoleText("")
	, character(Character)
{
	text = character;
}

ConsoleCharacter::ConsoleCharacter(const char Character, const ConsolePoint2D& Position)
	: ConsoleText("", Position)
	, character(Character)
{
	text = character;
}

ConsoleCharacter::ConsoleCharacter(const char Character, const int x, const int y)
	: ConsoleText("", x, y)
	, character(Character)
{
	text = character;
}

ConsoleCharacter::ConsoleCharacter(const ConsoleCharacter& character2)
	: ConsoleText(character2)
	, character(character2.character)
{
	text = character;
}

ConsoleCharacter::ConsoleCharacter(ConsoleCharacter&& character2)
	: ConsoleText(character2)
	, character(character2.character)
{
	text = character;
	character2.~ConsoleCharacter();
}

const ConsoleCharacter& ConsoleCharacter::operator=(const ConsoleCharacter& character2)
{
	if (this == &character2)
		return*this;
	text = character;
	ConsoleText::operator=(character2);
	character = character2.character;
	return*this;
}

const bool ConsoleCharacter::operator==(char character2) const
{
	return character == character2;
}

ConsoleCharacter::operator char() const
{
	return character;
}

const char& ConsoleCharacter::getCharacter() const
{
	return character;
}

const ConsoleCharacter& ConsoleCharacter::setCharacter(const char character2)
{
	character = character2;
	return*this;
}
