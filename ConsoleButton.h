#pragma once
#include <vector>
#include "ConsoleText.h"

namespace console_engine
{
    class ConsoleButton
        : public ConsoleText
    {
    private:
        //  color
        int _defaultBackColor = (int)ConsoleColor::Light;
        int _defaultForeColor = (int)ConsoleColor::Black;
            //  getMouse without get leftDown
        int _inactiveBackColor = (int)ConsoleColor::White;
        int _inactiveForeColor = (int)ConsoleColor::Black;
        int _activeBackColor =
            (int)ConsoleColor::White + (int)ConsoleColor::Light;
        int _activeForeColor = (int)ConsoleColor::Black;
        int _unavailableDefaultBackColor = (int)ConsoleColor::Red;
        int _unavailableDefaultForeColor = (int)ConsoleColor::Black;
        int _unavailableInactiveBackColor =
            (int)ConsoleColor::Red + (int)ConsoleColor::Light;
        int _unavailableInactiveForeColor = (int)ConsoleColor::Black;

        //  state
        bool _catchMouse = false;
        bool _available = true;
        bool _active = false;
            //  use Drag() instead of activateFunction() if true
        bool _draggable = false;

        //  action
        void(*_activateFunction)();
        int _dragOffset = 0;
        void Drag();

        //  others
        const bool CatchMouse();

        explicit ConsoleButton();
    public:
        //  constructor
        ConsoleButton(const std::string text);
        ConsoleButton(const std::string text, const ConsolePoint2D position);
        ConsoleButton(const std::string text, const int x, const int y);
        ConsoleButton(const std::string text, void(*activateFunction)());
        ConsoleButton(const ConsoleButton& button);
        ConsoleButton(ConsoleButton&& button);
        virtual const ConsoleButton& operator=(const ConsoleButton& button);

        //  get
        virtual ConsoleButton* GetClone()const override;
        const bool IsDraggable()const;

        //  set color
        ConsoleButton& SetDefaultBackColor(int color);
        ConsoleButton& SetDefaultForeColor(int color);
        ConsoleButton& SetInactiveBackColor(int color);
        ConsoleButton& SetInactiveForeColor(int color);
        ConsoleButton& SetActiveBackColor(int color);
        ConsoleButton& SetActiveForeColor(int color);
        ConsoleButton& SetUnavailableDefaultBackColor(int color);
        ConsoleButton& SetUnavailableDefaultForeColor(int color);
        ConsoleButton& SetUnavailableInactiveBackColor(int color);
        ConsoleButton& SetUnavailableInactiveForeColor(int color);

        //  set state
        ConsoleButton& SetAvailable(const bool available);
        ConsoleButton& SetActivateFunction(void(*activateFunction)());

        //  others
        const ConsoleButton& UpdateState();
        const ConsoleButton& SetDraggable(const bool draggable);
    };
}