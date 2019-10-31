#pragma once
#include "ConsoleController.h"
#pragma comment(lib, "ConsoleController.lib")
#include "ConsoleMap.h"
#include <string>

namespace ConsoleEngine
{
	class ConsoleObject
	{
	protected:
		std::string text;
		ConsolePoint2D position = { 0,0 };

		explicit ConsoleObject();
	public:
		ConsoleObject(const std::string Text);
		ConsoleObject(const std::string Text, const ConsolePoint2D Position);
		ConsoleObject(const std::string Text, const int x, const int y);
		ConsoleObject(const ConsoleObject& object2);
		ConsoleObject(ConsoleObject&& object2);
		virtual const ConsoleObject& operator=(const ConsoleObject& object2);

		//	get
		const std::string getText()const;
		const ConsolePoint2D getPosition()const;

		//	set
		ConsoleObject& setText(const std::string Text);
		ConsoleObject& setPosition(const ConsolePoint2D position2);
		ConsoleObject& setPosition(const int x, const int y);

		//	others
		virtual const ConsoleObject& render()const;
	};
}