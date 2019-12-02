#include "ConsoleMap.h"
using namespace console_engine;

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
    :_x(0), _y(0)
{
}

ConsolePoint2D::ConsolePoint2D(const ConsolePoint2D& Position)
    : _x(Position._x), _y(Position._y)
{
}

ConsolePoint2D::ConsolePoint2D(const COORD& Position)
    : _x(Position.X), _y(Position.Y)
{
}

ConsolePoint2D::ConsolePoint2D(ConsolePoint2D&& Position)
    : _x(Position._x), _y(Position._y)
{
    Position.~ConsolePoint2D();
}

ConsolePoint2D::ConsolePoint2D(const int X, const int Y)
    : _x(X), _y(Y)
{
}

const ConsolePoint2D& ConsolePoint2D::operator=(const ConsolePoint2D Position)
{
    _x = Position._x;
    _y = Position._y;
    return*this;
}

const ConsolePoint2D& ConsolePoint2D::operator=(const COORD Position)
{
    _x = Position.X;
    _y = Position.Y;
    return*this;
}

const bool ConsolePoint2D::operator==(const ConsolePoint2D& Position) const
{
    return _x == Position._x && _y == Position._y;
}

const bool ConsolePoint2D::operator!=(const ConsolePoint2D& Position) const
{
    return !operator==(Position);
}

ConsolePoint2D::operator COORD() const
{
    return { short(_x),short(_y) };
}

const int ConsolePoint2D::GetX() const
{
    return _x;
}

const int ConsolePoint2D::GetY() const
{
    return _y;
}

const bool ConsolePoint2D::exist() const
{
    return _x != -1 || _y != -1;
}

void ConsolePoint2D::Set(const ConsolePoint2D Position)
{
    _x = Position._x;
    _y = Position._y;
}

void ConsolePoint2D::Set(const int X, const int Y)
{
    _x = X;
    _y = Y;
}

void ConsolePoint2D::RandomSet(const int MaxWidth, const int MaxHeight)
{
    _x = Rand() % MaxWidth;
    _y = Rand() % MaxHeight;
}

void ConsolePoint2D::RandomSet(
    const int Top,
    const int Bottom,
    const int Left,
    const int Right)
{
    _x = Rand() % (Right - Left) + Left;
    _y = Rand() % (Bottom - Top) + Top;
}
