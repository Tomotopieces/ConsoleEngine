#include "ConsoleMap.h"

int Rand()
{
	static bool Seed = false;
	if (!Seed) {
		Seed = true;
		srand((unsigned)time(NULL));
	}
	return rand();
}

ConsolePoint2D::ConsolePoint2D()
	:x(0), y(0)
{
}

ConsolePoint2D::ConsolePoint2D(const ConsolePoint2D& pos2)
	: x(pos2.x), y(pos2.y)
{
}

ConsolePoint2D::ConsolePoint2D(const COORD& pos2)
	: x(pos2.X), y(pos2.Y)
{
}

ConsolePoint2D::ConsolePoint2D(ConsolePoint2D&& pos2)
	: x(pos2.x), y(pos2.y)
{
	pos2.~ConsolePoint2D();
}

ConsolePoint2D::ConsolePoint2D(const int X, const int Y)
	: x(X), y(Y)
{
}

const ConsolePoint2D& ConsolePoint2D::operator=(const ConsolePoint2D pos2)
{
	x = pos2.x;
	y = pos2.y;
	return*this;
}

const ConsolePoint2D& ConsolePoint2D::operator=(const COORD pos2)
{
	x = pos2.X;
	y = pos2.Y;
	return*this;
}

const bool ConsolePoint2D::operator==(const ConsolePoint2D& pos2) const
{
	return x == pos2.x && y == pos2.y;
}

const bool ConsolePoint2D::operator!=(const ConsolePoint2D& pos2) const
{
	return !operator==(pos2);
}

ConsolePoint2D::operator COORD() const
{
	return { short(x),short(y) };
}

const int ConsolePoint2D::getX() const
{
	return x;
}

const int ConsolePoint2D::getY() const
{
	return y;
}

const bool ConsolePoint2D::exist() const
{
	return x != -1 || y != -1;
}

void ConsolePoint2D::reSet(const ConsolePoint2D pos2)
{
	x = pos2.x;
	y = pos2.y;
}

void ConsolePoint2D::reSet(const int X, const int Y)
{
	x = X;
	y = Y;
}

void ConsolePoint2D::randomSet(const int MaxWidth, const int MaxHeight)
{
	x = Rand() % MaxWidth;
	y = Rand() % MaxHeight;
}

void ConsolePoint2D::randomSet(const int Top, const int Bottom, const int Left, const int Right)
{
	x = Rand() % (Right - Left) + Left;
	y = Rand() % (Bottom - Top) + Top;
}