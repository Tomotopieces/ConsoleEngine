#pragma once
#include "ConsoleObject.h"
using namespace ConsoleController;

class ConsoleText	//控制台文本
	: public ConsoleObject
{
public:
	enum RenderMode {
		Normal,					//普通
		HorizontallyCentered,	//水平居中
		VerticallyCentered		//垂直居中
	};
private:
	int backColor = black;		//背景色
	int foreColor = light;		//字色
	RenderMode currentMode = Normal; //当前输出模式

	explicit ConsoleText();
public:
	ConsoleText(const std::string Text);
	ConsoleText(const std::string Text, const ConsolePoint2D Position);
	ConsoleText(const std::string Text, const int x, const int y);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	const ConsoleText& operator=(const ConsoleText& text2);

	//设置颜色
	const ConsoleText& setBackColor(const int color2);
	const ConsoleText& setForeColor(const int color2);
	const ConsoleText& setRenderMode(const RenderMode newMode);

	const ConsoleText& render()const;	//绘制
};