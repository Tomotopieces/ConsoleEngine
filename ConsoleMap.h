#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

namespace console_engine
{
    // random function    (set random seed once)
    int Rand();

    class ConsolePoint2D
    {
    private:
        int _x;
        int _y;
    public:
        //  constructor
        ConsolePoint2D();
        ConsolePoint2D(const ConsolePoint2D& Position);
        ConsolePoint2D(const COORD& Position);
        ConsolePoint2D(ConsolePoint2D&& Position);
        ConsolePoint2D(const int X, const int Y);
        const ConsolePoint2D& operator=(const ConsolePoint2D Position);
        const ConsolePoint2D& operator=(const COORD Position);

        //  equal operator
        const bool operator==(const ConsolePoint2D& Position)const;
        const bool operator!=(const ConsolePoint2D& Position)const;

        //  transform
        operator COORD()const;

        //  get
        const int GetX()const;
        const int GetY()const;

        //  set
        void Set(const ConsolePoint2D Position);
        void Set(const int X, const int Y);
        void RandomSet(const int MaxWidth, const int MaxHeight);
        void RandomSet(
            const int Top,
            const int Bottom,
            const int Left,
            const int Right
        );

        //  others
        const bool exist()const;
    };

    //****************************************
    //****************************************

    template<typename T>
    class ConsoleMap2D
    {
        friend class GameFunction;
    private:
        std::vector<std::vector<T>> _map;
        int _width;
        int _height;

        explicit ConsoleMap2D();
    public:
        ConsoleMap2D(const int width, const int height);
        ConsoleMap2D(const ConsoleMap2D& Map);
        ConsoleMap2D(ConsoleMap2D&& Map);
        virtual const ConsoleMap2D<T>& operator=(const ConsoleMap2D<T>& Map);
        virtual const bool operator==(const ConsoleMap2D<T>& Map)const;
        virtual const bool operator!=(const ConsoleMap2D<T>& Map)const;

        const std::vector<T>& operator[](const int x)const;    // get, can't set
        const T operator[](const ConsolePoint2D pos)const;    // ibid

        // get
        const int GetWidth()const;
        const int GetHeight()const;
        const std::vector<std::vector<T>> GetMap()const;
        const T& GetPoint(const int x, const int y)const;
        const T& GetPoint(const ConsolePoint2D pos)const;

        // set
        ConsoleMap2D<T>& SetWidth(const int Width);
        ConsoleMap2D<T>& SetHeight(const int Height);
        ConsoleMap2D<T>& SetMap(const ConsoleMap2D<T>& Map);
        ConsoleMap2D<T>& SetPoint(const int x, const int y, const T& Data2);
        ConsoleMap2D<T>& SetPoint(ConsolePoint2D pos, const T& Data2);

        // others
        const ConsolePoint2D Find(T& data2)const;
        const std::vector<ConsolePoint2D> FindAll(T& data2)const;
    };

    template<typename T>
    ConsoleMap2D<T>::ConsoleMap2D(const int Width, const int Height)
        : _map(std::vector<std::vector<T>>
        (
            Width,
            std::vector<T>(Height))
        )
        , _width(Width)
        , _height(Height)
    {
    }

    template<typename T>
    ConsoleMap2D<T>::ConsoleMap2D(const ConsoleMap2D& Map)
        : _map(Map._map), _width(Map._width), _height(Map._height)
    {
    }

    template<typename T>
    ConsoleMap2D<T>::ConsoleMap2D(ConsoleMap2D&& Map)
        : _map(Map._map), _width(Map._width), _height(Map._height)
    {
        Map.~Map();
    }

    template<typename T>
    const ConsoleMap2D<T>& ConsoleMap2D<T>::operator=(
        const ConsoleMap2D<T>& Map
        )
    {
        _map = Map._map;
        _width = Map._width;
        _height = Map._height;
        return*this;
    }

    template<typename T>
    inline const bool ConsoleMap2D<T>::operator==(
        const ConsoleMap2D<T>& Map
        ) const
    {
        for (int x = 0; x < _width; ++x)
            for (int y = 0; y < _height; ++y)
                if (GetPoint(x, y) != Map.GetPoint(x, y))
                    return false;
        return true;
    }

    template<typename T>
    inline const bool ConsoleMap2D<T>::operator!=(
        const ConsoleMap2D<T>& Map
        ) const
    {
        return !operator==(Map);
    }

    template<typename T>
    inline const std::vector<T>& ConsoleMap2D<T>::operator[](const int x) const
    {
        return _map[x];
    }

    template<typename T>
    inline const T ConsoleMap2D<T>::operator[](const ConsolePoint2D pos) const
    {
        if (pos.exist())
            return GetPoint(pos);
        return T();
    }

    template<typename T>
    inline const int ConsoleMap2D<T>::GetWidth() const
    {
        return _width;
    }

    template<typename T>
    inline const int ConsoleMap2D<T>::GetHeight() const
    {
        return _height;
    }

    template<typename T>
    const std::vector<std::vector<T>> ConsoleMap2D<T>::GetMap() const
    {
        return _map;
    }

    template<typename T>
    const T& ConsoleMap2D<T>::GetPoint(const int x, const int y) const
    {
        return _map[x][y];
    }

    template<typename T>
    const T& ConsoleMap2D<T>::GetPoint(const ConsolePoint2D pos) const
    {
        int x = pos.GetX() < _width ? pos.GetX() : _width - 1;
        int y = pos.GetY() < _height ? pos.GetY() : _height - 1;
        return _map[x][y];
    }

    template<typename T>
    inline ConsoleMap2D<T>& ConsoleMap2D<T>::SetWidth(const int Width)
    {
        _width = Width;
        return*this;
    }

    template<typename T>
    inline ConsoleMap2D<T>& ConsoleMap2D<T>::SetHeight(const int Height)
    {
        _height = Height;
        return*this;
    }

    template<typename T>
    ConsoleMap2D<T>& ConsoleMap2D<T>::SetMap(const ConsoleMap2D<T>& Map)
    {
        this->_map = Map._map;
        _width = Map._width;
        _height = Map._height;
        return*this;
    }

    template<typename T>
    ConsoleMap2D<T>& ConsoleMap2D<T>::SetPoint(
        const int x,
        const int y,
        const T& Data2
    )
    {
        _map[x][y] = Data2;
        return*this;
    }

    template<typename T>
    ConsoleMap2D<T>& ConsoleMap2D<T>::SetPoint(
        ConsolePoint2D pos,
        const T& Data2
    )
    {
        _map[pos.GetX()][pos.GetY()] = Data2;
        return*this;
    }

    template<typename T>
    inline const ConsolePoint2D ConsoleMap2D<T>::Find(T& data2) const
    {
        for (int x = 0; x < _width; ++x)
            for (int y = 0; y < _height; ++y)
                if (GetPoint(x, y) != data2)
                    return ConsolePoint2D(x, y);
        return ConsolePoint2D(-1, -1);
    }

    template<typename T>
    inline const std::vector<ConsolePoint2D> ConsoleMap2D<T>::FindAll(
        T& data2
    ) const
    {
        std::vector<ConsolePoint2D> list;
        for (int x = 0; x < _width; ++x)
            for (int y = 0; y < _height; ++y)
                if (GetPoint(x, y) != data2)
                    list.push_back(ConsolePoint2D(x, y));
        return list;
    }

}