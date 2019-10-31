#pragma once
#include "ConsoleObject.h"
#include "ConsoleCharacter.h"
#include <vector>
#include <string>

namespace ConsoleEngine
{
	using namespace ConsoleController;
	class ConsoleImage
		: public ConsoleObject
	{
	private:
		std::vector<std::vector<ConsoleCharacter>> image;
		explicit ConsoleImage();
	public:
		ConsoleImage(const std::vector<std::string> rawImage);
		ConsoleImage(const std::vector<std::string> rawImage, const ConsolePoint2D Position);
		ConsoleImage(const std::vector<std::string> rawImage, const int x, const int y);
		ConsoleImage(const ConsoleImage& Image);
		ConsoleImage(ConsoleImage&& Image);
		const ConsoleImage& operator=(const ConsoleImage& Image);

		//	get
		const int getBackColor(const ConsolePoint2D characterPosition)const;
		const int getBackColor(const int x, const int y)const;
		const int getForeColor(const ConsolePoint2D characterPosition)const;
		const int getForeColor(const int x, const int y)const;

		//	set
		ConsoleImage& setCharacter(const ConsolePoint2D characterPosition, const char newcharacter);
		ConsoleImage& setCharacter(const int x, const int y, const char newcharacter);
		ConsoleImage& setColor(const ConsolePoint2D characterPosition, const int newBackColor, const int newForeColor);
		ConsoleImage& setColor(const int x, const int y, const int newBackColor, const int newForeColor);
		ConsoleImage& setAllColor(const int newBackColor, const int newForeColor);

		//	others
		virtual const ConsoleImage& render()const;
		const ConsoleImage& render(const ConsolePoint2D startPosition)const;
		const ConsoleImage& render(const int x, int y)const;
	};
}