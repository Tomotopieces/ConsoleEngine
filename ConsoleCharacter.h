#pragma once
#include "ConsoleObject.h"
#include "ConsoleText.h"

namespace ConsoleEngine
{
	class ConsoleCharacter
		: public ConsoleText
		, private ObjectInterface
	{
	private:
		char character = ' ';
		explicit ConsoleCharacter();
	public:
		//	constructor
		ConsoleCharacter(const char Character);
		ConsoleCharacter(const char Character, const ConsolePoint2D& Position);
		ConsoleCharacter(const char Character, const int x, const int y);
		ConsoleCharacter(const ConsoleCharacter& Character);
		ConsoleCharacter(ConsoleCharacter&& Character);
		const ConsoleCharacter& operator=(const ConsoleCharacter& Character);
		const bool operator==(char Character)const;
		operator char()const;

		//	get
		ConsoleCharacter* getClone()const override;
		const char& getCharacter()const;

		//	set
		const ConsoleCharacter& setCharacter(const char character2);
	};
}