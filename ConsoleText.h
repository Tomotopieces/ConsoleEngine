#pragma once
#include "ConsoleObject.h"

namespace console_engine
{
    using namespace consolr_controller;

    class ConsoleText
        : public ConsoleObject
    {
    private:
        int _backColor = (int)ConsoleColor::Black;
        int _foreColor = (int)ConsoleColor::Light;
        RenderMode _currentMode = RenderMode::Normal;

        explicit ConsoleText();
    public:
        //  constructor
        ConsoleText(const std::string text);
        ConsoleText(const std::string text, const ConsolePoint2D position);
        ConsoleText(const std::string text, const int x, const int y);
        ConsoleText(const ConsoleText& text);
        ConsoleText(ConsoleText&& text);
        virtual const ConsoleText& operator=(const ConsoleText& text);
        virtual const ConsoleText& operator=(const std::string& text);

        //  get
        virtual ConsoleText* GetClone()const override;
        const int GetBackColor()const;
        const int GetForeColor()const;

        //  set
        ConsoleText& SetBackColor(const int color);
        ConsoleText& SetForeColor(const int color);
        ConsoleText& SetRenderMode(const RenderMode mode);

        //  others
        virtual const ConsoleText& Render()const override;
    };
}