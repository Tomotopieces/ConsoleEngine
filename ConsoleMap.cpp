#include "ConsoleMap.h"
using namespace ConsoleEngine;

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

ConsolePoint2D::ConsolePoint2D(const ConsolePoint2D& Position)
	: x(Position.x), y(Position.y)
{
}

ConsolePoint2D::ConsolePoint2D(const COORD& Position)
	: x(Position.X), y(Position.Y)
{
}

ConsolePoint2D::ConsolePoint2D(ConsolePoint2D&& Position)
	: x(Position.x), y(Position.y)
{
	Position.~ConsolePoint2D();
}

ConsolePoint2D::ConsolePoint2D(const int X, const int Y)
	: x(X), y(Y)
{
}

const ConsolePoint2D& ConsolePoint2D::operator=(const ConsolePoint2D Position)
{
	x = Position.x;
	y = Position.y;
	return*this;
}

const ConsolePoint2D& ConsolePoint2D::operator=(const COORD Position)
{
	x = Position.X;
	y = Position.Y;
	return*this;
}

const bool ConsolePoint2D::operator==(const ConsolePoint2D& Position) const
{
	return x == Position.x && y == Position.y;
}

const bool ConsolePoint2D::operator!=(const ConsolePoint2D& Position) const
{
	return !operator==(Position);
}

ConsolePoint2D::operator COORD() const
{
	return { short(x),short(y) };
}

const int ConsolePoint2D::GetX() const
{
	return x;
}

const int ConsolePoint2D::GetY() const
{
	return y;
}

const bool ConsolePoint2D::exist() const
{
	return x != -1 || y != -1;
}

void ConsolePoint2D::Set(const ConsolePoint2D Position)
{
	x = Position.x;
	y = Position.y;
}

void ConsolePoint2D::Set(const int X, const int Y)
{
	x = X;
	y = Y;
}

void ConsolePoint2D::RandomSet(const int MaxWidth, const int MaxHeight)
{
	x = Rand() % MaxWidth;
	y = Rand() % MaxHeight;
}

void ConsolePoint2D::RandomSet(const int Top, const int Bottom, const int Left, const int Right)
{
	x = Rand() % (Right - Left) + Left;
	y = Rand() % (Bottom - Top) + Top;
}
