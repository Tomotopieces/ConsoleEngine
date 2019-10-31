#pragma once
#include "ConsoleObject.h"

namespace ConsoleEngine
{
	using namespace ConsoleController;
	enum RenderMode {
		Normal,
		HorizontallyCentered,
		VerticallyCentered
	};

	class ConsoleText
		: public ConsoleObject
	{
	protected:
		int backColor = black;
		int foreColor = light;
		RenderMode currentMode = Normal;
	private:
		explicit ConsoleText();
	public:
		ConsoleText(const std::string Text);
		ConsoleText(const std::string Text, const ConsolePoint2D Position);
		ConsoleText(const std::string Text, const int x, const int y);
		ConsoleText(const ConsoleText& Text);
		ConsoleText(ConsoleText&& Text);
		virtual const ConsoleText& operator=(const ConsoleText& Text);

		//	get
		const int getBackColor()const;
		const int getForeColor()const;

		//	set
		ConsoleText& setBackColor(const int Color);
		ConsoleText& setForeColor(const int Color);
		ConsoleText& setRenderMode(const RenderMode newMode);

		//	others
		virtual const ConsoleText& render()const;
	};
}