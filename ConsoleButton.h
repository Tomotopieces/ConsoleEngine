#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	using namespace ConsoleController;
	class ConsoleButton
		: public ConsoleObject
	{
	private:
		//	color
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

		//	state
		bool catchMouse = false;	//是否捕捉到鼠标
		bool available = true;		//是否可激活
		bool active = false;		//是否已激活

		//	action
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

		//	set color
		ConsoleButton& setDefaultBackColor(int Color);
		ConsoleButton& setDefaultForeColor(int Color);
		ConsoleButton& setInactiveBackColor(int Color);
		ConsoleButton& setInactiveForeColor(int Color);
		ConsoleButton& setActiveBackColor(int Color);
		ConsoleButton& setActiveForeColor(int Color);
		ConsoleButton& setUnavailableDefaultBackColor(int Color);
		ConsoleButton& setUnavailableDefaultForeColor(int Color);
		ConsoleButton& setUnavailableInactiveBackColor(int Color);
		ConsoleButton& setUnavailableInactiveForeColor(int Color);

		//	set state
		ConsoleButton& setAvailable(const bool Usable);
		ConsoleButton& setActivateFunction(void(*ActivateFunction)());

		//	others
		const ConsoleButton& updateState();	//更新按钮状态
		const ConsoleButton& render()const;	//绘制
	};
}