#pragma once
#include "ConsoleFunc.h"
#include "Game.h"
#include <string>
using namespace ConsoleFunction;

class ConsoleText
{
private:
	std::string text;
	int backColor = black;		//±³¾°É«
	int foreColor = light;		//×ÖÉ«
	ConsolePoint2D position = { 0,0 };

	explicit ConsoleText();
public:
	ConsoleText(const std::string Name);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	const ConsoleText& operator=(const ConsoleText& text2);

	const std::string getText()const;
	const ConsolePoint2D getPosition()const;
	const ConsoleText& setText(const std::string text2);

	const ConsoleText& setBackColor(int color2);
	const ConsoleText& setForeColor(int color2);

	const ConsoleText& setPosition(const ConsolePoint2D position2);
	const ConsoleText& setPosition(const int x, const int y);

	const ConsoleText& Render()const;
};