#pragma once
#include "ConsoleObject.h"
#include <vector>
using namespace ConsoleController;

class ConsoleButton	//控制台按钮
	: public ConsoleObject
{
private:
	int defaultBackColor = light;		//默认 背景色
	int defaultForeColor = black;		//默认 字色
	int inactiveBackColor = white;			//未激活 背景色
	int inactiveForeColor = black;			//未激活 字色
	int activeBackColor = white + light;		//激活 背景色
	int activeForeColor = black;				//激活 字色
	int unavailableDefaultBackColor = red;			//不可激活 默认 背景色
	int unavailableDefaultForeColor = black;		//不可激活 默认 字色
	int unavailableInactiveBackColor = red + light;		//不可激活 未激活 背景色
	int unavailableInactiveForeColor = black;			//不可激活 未激活 字色

	bool catchMouse = false;	//是否捕捉到鼠标
	bool available = true;		//是否可激活
	bool active = false;		//是否已激活

	void(*activateFunction)();	//激活函数

	const bool CatchMouse();	//捕捉鼠标检测

	explicit ConsoleButton();
public:
	ConsoleButton(const std::string Text);
	ConsoleButton(const std::string Text, const ConsolePoint2D Position);
	ConsoleButton(const std::string Text, const int x, const int y);
	ConsoleButton(const std::string Text, void(*ActivateFunction)());
	ConsoleButton(const ConsoleButton& option2);
	ConsoleButton(ConsoleButton&& option2);
	const ConsoleButton& operator=(const ConsoleButton& option2);

	//设置颜色
	const ConsoleButton& setDefaultBackColor(int color2);
	const ConsoleButton& setDefaultForeColor(int color2);
	const ConsoleButton& setInactiveBackColor(int color2);
	const ConsoleButton& setInactiveForeColor(int color2);
	const ConsoleButton& setActiveBackColor(int color2);
	const ConsoleButton& setActiveForeColor(int color2);
	const ConsoleButton& setUnavailableDefaultBackColor(int color2);
	const ConsoleButton& setUnavailableDefaultForeColor(int color2);
	const ConsoleButton& setUnavailableInactiveBackColor(int color2);
	const ConsoleButton& setUnavailableInactiveForeColor(int color2);

	const ConsoleButton& setAvailable(const bool Usable);
	const ConsoleButton& setActivateFunction(void(*ActivateFunction)());

	const ConsoleButton& updateState();	//更新按钮状态

	const ConsoleButton& render()const;	//绘制
};