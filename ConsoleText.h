#pragma once
#include "ConsoleFunc.h"
#include "Game.h"
#include <string>
using namespace ConsoleFunction;

class ConsoleText
{
private:
	std::string text;
	int backColor = black;		//背景色
	int foreColor = light;		//字色
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

	enum RenderMode {
		Normal,					//普通
		HorizontallyCentered,	//水平居中
		VerticallyCentered };	//垂直居中
	const ConsoleText& Render(RenderMode renderMode = Normal)const;
};