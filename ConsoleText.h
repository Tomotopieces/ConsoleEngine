#pragma once
#include "ConsoleObject.h"
using namespace ConsoleFunction;

class ConsoleText
	: public ConsoleObject
{
private:
	int backColor = black;		//背景色
	int foreColor = light;		//字色

	explicit ConsoleText();
public:
	ConsoleText(const std::string Text);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	const ConsoleText& operator=(const ConsoleText& text2);

	const ConsoleText& setBackColor(int color2);
	const ConsoleText& setForeColor(int color2);

	enum RenderMode {
		Normal,					//普通
		HorizontallyCentered,	//水平居中
		VerticallyCentered
	};	//垂直居中
	const ConsoleText& Render(RenderMode renderMode = Normal)const;
};