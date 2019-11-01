#pragma once
#include "ConsoleImage.h"
#include <vector>
#include <string>

namespace ConsoleEngine
{
	class ConsoleSprite
		: public ConsoleObject
	{
	private:
		ConsoleImage image;
		bool isTrigger = false;
		struct ColliderState
		{
			int width = 1;
			int height = 1;
			ConsolePoint2D upperLeft = { 0,0 };
		};
		ColliderState collider;
		explicit ConsoleSprite();
	public:
		//	construct by rawImage
		ConsoleSprite(const RawImage& Image);
		ConsoleSprite(const RawImage& Image, const ConsolePoint2D& Position);
		ConsoleSprite(const RawImage& Image, const int x, const int y);

		//	construct by ConsoleImage
		ConsoleSprite(const ConsoleImage& Image);
		ConsoleSprite(ConsoleImage&& Image);
		const ConsoleSprite& operator=(const ConsoleImage& Image);

		//	construct by other Sprite
		ConsoleSprite(const ConsoleSprite& Sprite);
		ConsoleSprite(ConsoleSprite&& Sprite);
		const ConsoleSprite& operator=(const ConsoleSprite& Sprite);

		//	get
		const ConsoleImage& getImage()const;
		const bool getIsTrigger()const;
		const int getColliderWidth()const;
		const int getColliderHeight()const;
		const ConsolePoint2D& getColliderStartPoint()const;

		//	set
		ConsoleSprite& setImgae(const ConsoleImage& Image);
		ConsoleSprite& setIsTrigger(const bool IsTrigger);
		ConsoleSprite& setColliderWidth(const int Width);
		ConsoleSprite& setColliderHeight(const int Height);
		ConsoleSprite& setColliderStartPoint(const ConsolePoint2D& Point);

		//	others
		const ConsoleSprite& render()const;
	};
}