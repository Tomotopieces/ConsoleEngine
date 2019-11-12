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
		virtual ConsoleSprite* GetClone()const override;
		const ConsoleImage& GetImage()const;
		const bool GetIsTrigger()const;
		const int GetColliderWidth()const;
		const int GetColliderHeight()const;
		const ConsolePoint2D& GetColliderStartPoint()const;

		//	set
		ConsoleSprite& SetImgae(const ConsoleImage& Image);
		ConsoleSprite& SetIsTrigger(const bool IsTrigger);
		ConsoleSprite& SetColliderWidth(const int Width);
		ConsoleSprite& SetColliderHeight(const int Height);
		ConsoleSprite& SetColliderStartPoint(const ConsolePoint2D& Point);

		//	others
		const ConsoleSprite& Render()const override;
	};
}