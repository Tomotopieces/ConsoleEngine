#pragma once
#include "ConsoleObject.h"
#include "ConsoleText.h"
using namespace ConsoleController;

class ConsoleCharacter
	: public ConsoleText
{
private:
	char character = ' ';
	explicit ConsoleCharacter();
public:
	ConsoleCharacter(const char Character);
	ConsoleCharacter(const char Character, const ConsolePoint2D& Position);
	ConsoleCharacter(const char Character, const int x, const int y);
	ConsoleCharacter(const ConsoleCharacter& character2);
	ConsoleCharacter(ConsoleCharacter&& character2);
	const ConsoleCharacter& operator=(const ConsoleCharacter& character2);
	const bool operator==(char character2)const;
	operator char()const;

	const char& getCharacter()const;
	const ConsoleCharacter& setCharacter(const char character2);
};