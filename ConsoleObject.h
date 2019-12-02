#pragma once
#include <string>
#include "ConsoleController.h"
#include "ConsoleMap.h"

namespace console_engine
{
    enum class RenderMode {
        Normal = 0,
        HorizontallyCentered = 1,
        VerticallyCentered = 2,
        CompletelyCentered = 3,
        PointCentered = 4
    };

    class ConsoleObject
    {
    private:
        std::string _text;
        ConsolePoint2D _position = { 0,0 };
        explicit ConsoleObject();
    public:
        //  constructor
        ConsoleObject(const std::string text);
        ConsoleObject(const std::string text, const ConsolePoint2D& position);
        ConsoleObject(const std::string text, const int x, const int y);
        ConsoleObject(const ConsoleObject& object);
        ConsoleObject(ConsoleObject&& object);
        virtual const ConsoleObject& operator=(const ConsoleObject& object);

        //  get
        virtual ConsoleObject* GetClone()const;
        const std::string GetText()const;
        const ConsolePoint2D GetPosition()const;

        //  set
        ConsoleObject& SetText(const std::string text);
        ConsoleObject& SetPosition(const ConsolePoint2D position2);
        ConsoleObject& SetPosition(const int x, const int y);

        //  others
        virtual const ConsoleObject& Render()const;
    };
}