#pragma once
#include "ConsoleController.h"
#pragma comment(lib, "ConsoleController.lib")
#include "ConsoleMap.h"
#include <string>

class ConsoleObject	//控制台物体
{
protected:
	std::string text;					//文本
	ConsolePoint2D position = { 0,0 };	//坐标

	explicit ConsoleObject();
public:
	ConsoleObject(const std::string Text);
	ConsoleObject(const std::string Text, const ConsolePoint2D Position);
	ConsoleObject(const std::string Text, const int x, const int y);
	ConsoleObject(const ConsoleObject& object2);
	ConsoleObject(ConsoleObject&& object2);
	virtual const ConsoleObject& operator=(const ConsoleObject& object2);

	const std::string getText()const;
	const ConsolePoint2D getPosition()const;

	const ConsoleObject& setText(const std::string text2);
	const ConsoleObject& setPosition(const ConsolePoint2D position2);
	const ConsoleObject& setPosition(const int x, const int y);

	virtual const ConsoleObject& render()const;	//绘制
};