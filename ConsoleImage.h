#pragma once
#include "ConsoleObject.h"
#include "ConsoleCharacter.h"
#include <vector>
#include <string>

namespace ConsoleEngine
{
	using namespace ConsoleController;

	typedef std::vector<std::string> RawImage;	//	RawImage is a vector of string.

	class ConsoleImage
		: public ConsoleObject
	{
	private:
		std::vector<std::vector<ConsoleCharacter>> image;

		//	others
		const void copyFromRawImage(const RawImage& rawImage);

		explicit ConsoleImage();
	public:
		//	constructor
		ConsoleImage(const RawImage& rawImage);
		ConsoleImage(const RawImage& rawImage, const ConsolePoint2D Position);
		ConsoleImage(const RawImage& rawImage, const int x, const int y);
		ConsoleImage(const ConsoleImage& Image);
		ConsoleImage(const ConsoleImage& Image, const ConsolePoint2D Position);
		ConsoleImage(const ConsoleImage& Image, const int x, const int y);
		ConsoleImage(ConsoleImage&& Image);
		const ConsoleImage& operator=(const RawImage& rawImage);
		const ConsoleImage& operator=(const ConsoleImage& Image);

		//	get
		virtual ConsoleImage* GetClone()const override;
		const int GetBackColor(const ConsolePoint2D characterPosition)const;
		const int GetBackColor(const int x, const int y)const;
		const int GetForeColor(const ConsolePoint2D characterPosition)const;
		const int GetForeColor(const int x, const int y)const;

		//	set
		ConsoleImage& SetCharacter(const ConsolePoint2D characterPosition, const char newcharacter);
		ConsoleImage& SetCharacter(const int x, const int y, const char newcharacter);
		ConsoleImage& SetColor(const ConsolePoint2D characterPosition, const int newBackColor, const int newForeColor);
		ConsoleImage& SetColor(const int x, const int y, const int newBackColor, const int newForeColor);
		ConsoleImage& SetAllColor(const int newBackColor, const int newForeColor);

		//	others
		virtual const ConsoleImage& Render()const override;
		const ConsoleImage& Render(const ConsolePoint2D startPosition)const;
		const ConsoleImage& Render(const int x, int y)const;
	};
}