#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#pragma comment(lib, "ConsoleFunc.lib")

int Rand();

// 2D Map Point
class Point {
private:
	int x;
	int y;
public:
	Point();
	Point(const Point& pos2);
	Point(const COORD& pos2);
	Point(Point&& pos2);
	Point(const int X, const int Y);
	const Point& operator=(const Point pos2);
	const Point& operator=(const COORD pos2);
	const bool operator==(const Point& pos2)const;
	const bool operator!=(const Point& pos2)const;
	operator COORD()const;

	const int getX()const;
	const int getY()const;

	const bool exist()const;
	void ReSet(const int MaxWidth, const int MaxHeight);
};

//****************************************
//****************************************

// 2D Map
template<typename T>
class GameMap {
	friend class GameFunction;
private:
	std::vector<std::vector<T>> Map;
	int width;
	int height;

	explicit GameMap();
public:
	GameMap(const int width, const int height);
	GameMap(const GameMap& Map2);
	GameMap(GameMap&& Map2);
	virtual const GameMap<T>& operator=(const GameMap<T>& Map2);
	virtual const bool operator==(const GameMap<T>& Map2)const;
	virtual const bool operator!=(const GameMap<T>& Map2)const;

	// get, not set
	const std::vector<T>& operator[](const int x)const;
	const T operator[](const Point pos)const;
	
	// get
	const int getWidth()const;
	const int getHeight()const;
	const std::vector<std::vector<T>> getMap()const;
	const T& getPoint(const int x, const int y)const;
	const T& getPoint(const Point pos)const;

	// set
	const GameMap<T>& setWidth(const int Width);
	const GameMap<T>& setHeight(const int Height);
	const GameMap<T>& setMap(const GameMap<T>& Map2);
	const GameMap<T>& setPoint(const int x, const int y, const T& Data2);
	const GameMap<T>& setPoint(Point pos, const T& Data2);

	// others
	const Point find(T& data2)const;
	const std::vector<Point> findAll(T& data2)const;
};

template<typename T>
GameMap<T>::GameMap(const int Width, const int Height)
	:Map(std::vector<std::vector<T>>(Width, std::vector<T>(Height))), width(Width), height(Height)
{
}

template<typename T>
GameMap<T>::GameMap(const GameMap& Map2)
	: Map(Map2.Map), width(Map2.width), height(Map2.height)
{
}

template<typename T>
GameMap<T>::GameMap(GameMap&& Map2)
	: Map(Map2.Map), width(Map2.width), height(Map2.height)
{
	Map2.~Map();
}

template<typename T>
const GameMap<T>& GameMap<T>::operator=(const GameMap<T>& Map2)
{
	Map = Map2.Map;
	width = Map2.width;
	height = Map2.height;
	return*this;
}

template<typename T>
inline const bool GameMap<T>::operator==(const GameMap<T>& Map2)const
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
			if (getPoint(x, y) != Map2.getPoint(x, y))
				return false;
	return true;
}

template<typename T>
inline const bool GameMap<T>::operator!=(const GameMap<T>& Map2) const
{
	return !operator==(Map2);
}

template<typename T>
inline const std::vector<T>& GameMap<T>::operator[](const int x) const
{
	return Map[x];
}

template<typename T>
inline const T GameMap<T>::operator[](const Point pos) const
{
	if(pos.exist())
		return getPoint(pos);
	return T();
}

template<typename T>
inline const int GameMap<T>::getWidth() const
{
	return width;
}

template<typename T>
inline const int GameMap<T>::getHeight() const
{
	return height;
}

template<typename T>
const std::vector<std::vector<T>> GameMap<T>::getMap() const
{
	return Map;
}

template<typename T>
const T& GameMap<T>::getPoint(const int x, const int y) const
{
	return Map[x][y];
}

template<typename T>
const T& GameMap<T>::getPoint(const Point pos) const
{
	int x = pos.getX() < width ? pos.getX() : width - 1;
	int y = pos.getY() < height ? pos.getY() : height - 1;
	return Map[x][y];
}

template<typename T>
inline const GameMap<T>& GameMap<T>::setWidth(const int Width)
{
	width = Width;
	return*this;
}

template<typename T>
inline const GameMap<T>& GameMap<T>::setHeight(const int Height)
{
	height = Height;
	return*this;
}

template<typename T>
const GameMap<T>& GameMap<T>::setMap(const GameMap<T>& Map2)
{
	this->Map = Map2.Map;
	width = Map2.width;
	height = Map2.height;
	return*this;
}

template<typename T>
const GameMap<T>& GameMap<T>::setPoint(const int x, const int y, const T& Data2)
{
	Map[x][y] = Data2;
	return*this;
}

template<typename T>
const GameMap<T>& GameMap<T>::setPoint(Point pos, const T& Data2)
{
	Map[pos.getX()][pos.getY()] = Data2;
	return*this;
}

template<typename T>
inline const Point GameMap<T>::find(T& data2) const
{
	for (int x = 0; x < width; ++x)
		for (int y = 0; y < height; ++y)
			if (getPoint(x, y) != data2)
				return Point(x, y);
	return Point(-1, -1);
}

template<typename T>
inline const std::vector<Point> GameMap<T>::findAll(T& data2) const
{
	std::vector<Point> list;
	for (int x = 0; x < width++; x)
		for (int y = 0; y < height; ++y)
			if (getPoint(x, y) != data2)
				list.push_back(Point(x, y));
	return list;
}
