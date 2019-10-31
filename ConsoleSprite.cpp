#include "ConsoleSprite.h"
using namespace ConsoleEngine;

ConsoleEngine::ConsoleSprite::ConsoleSprite(const std::vector<std::string> Image)
	: ConsoleObject("")
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const std::vector<std::string> Image, const ConsolePoint2D Position)
	: ConsoleObject("", Position)
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const std::vector<std::string> Image, const int x, const int y)
	: ConsoleObject("", x, y)
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const ConsoleImage& Image)
	: ConsoleObject("")
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(ConsoleImage&& Image)
	: ConsoleObject("")
	, image(Image)
{
	Image.~ConsoleImage();
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const ConsoleSprite& Sprite)
	: ConsoleObject(Sprite)
	,image(Sprite.image)
	, isTrigger(Sprite.isTrigger)
	, collider(Sprite.collider)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(ConsoleSprite&& Sprite)
	: ConsoleObject(Sprite)
	, image(Sprite.image)
	, isTrigger(Sprite.isTrigger)
	, collider(Sprite.collider)
{
	Sprite.~ConsoleSprite();
}

const ConsoleSprite& ConsoleEngine::ConsoleSprite::operator=(const ConsoleSprite& Sprite)
{
	ConsoleObject::operator=(Sprite);
	image = Sprite.image;
	isTrigger = Sprite.isTrigger;
	collider = Sprite.collider;
	return*this;
}

const ConsoleImage& ConsoleEngine::ConsoleSprite::getImage() const
{
	return image;
}

const bool ConsoleEngine::ConsoleSprite::getIsTrigger() const
{
	return isTrigger;
}

const int ConsoleEngine::ConsoleSprite::getColliderWidth() const
{
	return collider.width;
}

const int ConsoleEngine::ConsoleSprite::getColliderHeight() const
{
	return collider.height;
}

const ConsolePoint2D& ConsoleEngine::ConsoleSprite::getColliderStartPoint() const
{
	return collider.upperLeft;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::setImgae(const ConsoleImage& Image)
{
	image = Image;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::setIsTrigger(const bool IsTrigger)
{
	isTrigger = IsTrigger;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::setColliderWidth(const int Width)
{
	collider.width = Width;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::setColliderHeight(const int Height)
{
	collider.height = Height;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::setColliderStartPoint(const ConsolePoint2D& Point)
{
	collider.upperLeft = Point;
	return*this;
}

const ConsoleSprite& ConsoleEngine::ConsoleSprite::render() const
{
	image.render(position);
	return*this;
}

