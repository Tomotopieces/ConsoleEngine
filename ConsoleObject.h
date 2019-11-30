#pragma once
#include "ConsoleController.h"
#include "ConsoleMap.h"
#include <string>

namespace ConsoleEngine
{
	enum RenderMode {
		Normal = 0,
		HorizontallyCentered = 1,
		VerticallyCentered = 2,
		PointCentered = 4
	};

	class ConsoleObject
	{
	protected:
		std::string text;
		ConsolePoint2D position = { 0,0 };
		explicit ConsoleObject();
	public:
		//	constructor
		ConsoleObject(const std::string Text);
		ConsoleObject(const std::string Text, const ConsolePoint2D Position);
		ConsoleObject(const std::string Text, const int x, const int y);
		ConsoleObject(const ConsoleObject& object2);
		ConsoleObject(ConsoleObject&& object2);
		virtual const ConsoleObject& operator=(const ConsoleObject& object2);

		//	get
		virtual ConsoleObject* GetClone()const;
		const std::string GetText()const;
		const ConsolePoint2D GetPosition()const;

		//	set
		ConsoleObject& SetText(const std::string Text);
		ConsoleObject& SetPosition(const ConsolePoint2D position2);
		ConsoleObject& SetPosition(const int x, const int y);

		//	others
		virtual const ConsoleObject& Render()const;
	};
}