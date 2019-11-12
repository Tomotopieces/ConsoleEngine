#include "ConsoleCharacter.h"
#include <iostream>
using namespace ConsoleEngine;

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

ConsoleCharacter::ConsoleCharacter(const ConsoleCharacter& Character)
	: ConsoleText(Character)
	, character(Character.character)
{
	text = character;
}

ConsoleCharacter::ConsoleCharacter(ConsoleCharacter&& Character)
	: ConsoleText(Character)
	, character(Character.character)
{
	text = character;
	Character.~ConsoleCharacter();
}

const ConsoleCharacter& ConsoleCharacter::operator=(const ConsoleCharacter& Character)
{
	if (this == &Character)
		return*this;
	text = character;
	ConsoleText::operator=(Character);
	character = Character.character;
	return*this;
}

const bool ConsoleCharacter::operator==(char Character) const
{
	return character == Character;
}

ConsoleCharacter::operator char() const
{
	return character;
}

ConsoleCharacter* ConsoleEngine::ConsoleCharacter::GetClone() const
{
	ConsoleCharacter* clone = new ConsoleCharacter(*this);
	return clone;
}

const char& ConsoleCharacter::GetCharacter() const
{
	return character;
}

const ConsoleCharacter& ConsoleCharacter::SetCharacter(const char character2)
{
	character = character2;
	return*this;
}
