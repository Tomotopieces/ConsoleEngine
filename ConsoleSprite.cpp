#include "ConsoleSprite.h"
using namespace ConsoleEngine;

ConsoleEngine::ConsoleSprite::ConsoleSprite(const RawImage& Image)
	: ConsoleObject("")
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const RawImage& Image, const ConsolePoint2D& Position)
	: ConsoleObject("", Position)
	, image(Image)
{
}

ConsoleEngine::ConsoleSprite::ConsoleSprite(const RawImage& Image, const int x, const int y)
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

const ConsoleSprite& ConsoleEngine::ConsoleSprite::operator=(const ConsoleImage& Image)
{	// do not change "isTrigger" and "collider"
	ConsoleObject::operator=(Image);
	image = Image;
	return*this;
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

ConsoleSprite* ConsoleEngine::ConsoleSprite::GetClone() const
{
	ConsoleSprite* clone = new ConsoleSprite(*this);
	return clone;
}

const ConsoleImage& ConsoleEngine::ConsoleSprite::GetImage() const
{
	return image;
}

const bool ConsoleEngine::ConsoleSprite::GetIsTrigger() const
{
	return isTrigger;
}

const int ConsoleEngine::ConsoleSprite::GetColliderWidth() const
{
	return collider.width;
}

const int ConsoleEngine::ConsoleSprite::GetColliderHeight() const
{
	return collider.height;
}

const ConsolePoint2D& ConsoleEngine::ConsoleSprite::GetColliderStartPoint() const
{
	return collider.upperLeft;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::SetImgae(const ConsoleImage& Image)
{
	image = Image;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::SetIsTrigger(const bool IsTrigger)
{
	isTrigger = IsTrigger;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::SetColliderWidth(const int Width)
{
	collider.width = Width;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::SetColliderHeight(const int Height)
{
	collider.height = Height;
	return*this;
}

ConsoleSprite& ConsoleEngine::ConsoleSprite::SetColliderStartPoint(const ConsolePoint2D& Point)
{
	collider.upperLeft = Point;
	return*this;
}

const ConsoleSprite& ConsoleEngine::ConsoleSprite::Render() const
{
	image.Render(position);
	return*this;
}

