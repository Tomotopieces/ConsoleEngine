#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

namespace ConsoleEngine
{
	// random function	(set random seed once)
	int Rand();

	class ConsolePoint2D
	{
	private:
		int x;
		int y;
	public:
		//	constructor
		ConsolePoint2D();
		ConsolePoint2D(const ConsolePoint2D& Position);
		ConsolePoint2D(const COORD& Position);
		ConsolePoint2D(ConsolePoint2D&& Position);
		ConsolePoint2D(const int X, const int Y);
		const ConsolePoint2D& operator=(const ConsolePoint2D Position);
		const ConsolePoint2D& operator=(const COORD Position);

		//	equal operator
		const bool operator==(const ConsolePoint2D& Position)const;
		const bool operator!=(const ConsolePoint2D& Position)const;

		//	transform
		operator COORD()const;

		//	get
		const int getX()const;
		const int getY()const;

		//	set
		void reSet(const ConsolePoint2D Position);
		void reSet(const int X, const int Y);
		void randomSet(const int MaxWidth, const int MaxHeight);
		void randomSet(const int Top, const int Bottom, const int Left, const int Right);

		//	others
		const bool exist()const;
	};

	//****************************************
	//****************************************

	template<typename T>
	class ConsoleMap2D
	{
		friend class GameFunction;
	private:
		std::vector<std::vector<T>> map;
		int width;
		int height;

		explicit ConsoleMap2D();
	public:
		ConsoleMap2D(const int width, const int height);
		ConsoleMap2D(const ConsoleMap2D& Map);
		ConsoleMap2D(ConsoleMap2D&& Map);
		virtual const ConsoleMap2D<T>& operator=(const ConsoleMap2D<T>& Map);
		virtual const bool operator==(const ConsoleMap2D<T>& Map)const;
		virtual const bool operator!=(const ConsoleMap2D<T>& Map)const;

		const std::vector<T>& operator[](const int x)const;	// get, can't set
		const T operator[](const ConsolePoint2D pos)const;	// ibid

		// get
		const int getWidth()const;
		const int getHeight()const;
		const std::vector<std::vector<T>> getMap()const;
		const T& getPoint(const int x, const int y)const;
		const T& getPoint(const ConsolePoint2D pos)const;

		// set
		ConsoleMap2D<T>& setWidth(const int Width);
		ConsoleMap2D<T>& setHeight(const int Height);
		ConsoleMap2D<T>& setMap(const ConsoleMap2D<T>& Map);
		ConsoleMap2D<T>& setPoint(const int x, const int y, const T& Data2);
		ConsoleMap2D<T>& setPoint(ConsolePoint2D pos, const T& Data2);

		// others
		const ConsolePoint2D find(T& data2)const;
		const std::vector<ConsolePoint2D> findAll(T& data2)const;
	};

	template<typename T>
	ConsoleMap2D<T>::ConsoleMap2D(const int Width, const int Height)
		:map(std::vector<std::vector<T>>(Width, std::vector<T>(Height))), width(Width), height(Height)
	{
	}

	template<typename T>
	ConsoleMap2D<T>::ConsoleMap2D(const ConsoleMap2D& Map)
		: map(Map.map), width(Map.width), height(Map.height)
	{
	}

	template<typename T>
	ConsoleMap2D<T>::ConsoleMap2D(ConsoleMap2D&& Map)
		: map(Map.map), width(Map.width), height(Map.height)
	{
		Map.~Map();
	}

	template<typename T>
	const ConsoleMap2D<T>& ConsoleMap2D<T>::operator=(const ConsoleMap2D<T>& Map)
	{
		map = Map.map;
		width = Map.width;
		height = Map.height;
		return*this;
	}

	template<typename T>
	inline const bool ConsoleMap2D<T>::operator==(const ConsoleMap2D<T>& Map)const
	{
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
				if (getPoint(x, y) != Map.getPoint(x, y))
					return false;
		return true;
	}

	template<typename T>
	inline const bool ConsoleMap2D<T>::operator!=(const ConsoleMap2D<T>& Map) const
	{
		return !operator==(Map);
	}

	template<typename T>
	inline const std::vector<T>& ConsoleMap2D<T>::operator[](const int x) const
	{
		return map[x];
	}

	template<typename T>
	inline const T ConsoleMap2D<T>::operator[](const ConsolePoint2D pos) const
	{
		if (pos.exist())
			return getPoint(pos);
		return T();
	}

	template<typename T>
	inline const int ConsoleMap2D<T>::getWidth() const
	{
		return width;
	}

	template<typename T>
	inline const int ConsoleMap2D<T>::getHeight() const
	{
		return height;
	}

	template<typename T>
	const std::vector<std::vector<T>> ConsoleMap2D<T>::getMap() const
	{
		return map;
	}

	template<typename T>
	const T& ConsoleMap2D<T>::getPoint(const int x, const int y) const
	{
		return map[x][y];
	}

	template<typename T>
	const T& ConsoleMap2D<T>::getPoint(const ConsolePoint2D pos) const
	{
		int x = pos.getX() < width ? pos.getX() : width - 1;
		int y = pos.getY() < height ? pos.getY() : height - 1;
		return map[x][y];
	}

	template<typename T>
	inline ConsoleMap2D<T>& ConsoleMap2D<T>::setWidth(const int Width)
	{
		width = Width;
		return*this;
	}

	template<typename T>
	inline ConsoleMap2D<T>& ConsoleMap2D<T>::setHeight(const int Height)
	{
		height = Height;
		return*this;
	}

	template<typename T>
	ConsoleMap2D<T>& ConsoleMap2D<T>::setMap(const ConsoleMap2D<T>& Map)
	{
		this->map = Map.map;
		width = Map.width;
		height = Map.height;
		return*this;
	}

	template<typename T>
	ConsoleMap2D<T>& ConsoleMap2D<T>::setPoint(const int x, const int y, const T& Data2)
	{
		map[x][y] = Data2;
		return*this;
	}

	template<typename T>
	ConsoleMap2D<T>& ConsoleMap2D<T>::setPoint(ConsolePoint2D pos, const T& Data2)
	{
		map[pos.getX()][pos.getY()] = Data2;
		return*this;
	}

	template<typename T>
	inline const ConsolePoint2D ConsoleMap2D<T>::find(T& data2) const
	{
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
				if (getPoint(x, y) != data2)
					return ConsolePoint2D(x, y);
		return ConsolePoint2D(-1, -1);
	}

	template<typename T>
	inline const std::vector<ConsolePoint2D> ConsoleMap2D<T>::findAll(T& data2) const
	{
		std::vector<ConsolePoint2D> list;
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
				if (getPoint(x, y) != data2)
					list.push_back(ConsolePoint2D(x, y));
		return list;
	}

}