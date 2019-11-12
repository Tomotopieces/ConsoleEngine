#pragma once
#include "ConsoleObject.h"
#include "ConsoleText.h"

namespace ConsoleEngine
{
	class ConsoleCharacter
		: public ConsoleText
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
		virtual ConsoleCharacter* GetClone()const override;
		const char& GetCharacter()const;

		//	set
		const ConsoleCharacter& SetCharacter(const char character2);
	};
}