#pragma once
#include "ConsoleText.h"

namespace console_engine
{
    class ConsoleCharacter
        : public ConsoleText
    {
    private:
        char _character = ' ';
        explicit ConsoleCharacter();
    public:
        //  constructor
        ConsoleCharacter(const char character);
        ConsoleCharacter(const char character, const ConsolePoint2D& position);
        ConsoleCharacter(const char character, const int x, const int y);
        ConsoleCharacter(const ConsoleCharacter& character);
        ConsoleCharacter(ConsoleCharacter&& character);
        const ConsoleCharacter& operator=(const ConsoleCharacter& character);
        const bool operator==(char character)const;
        operator char()const;

        //  get
        virtual ConsoleCharacter* GetClone()const override;
        const char& GetCharacter()const;

        //  set
        const ConsoleCharacter& SetCharacter(const char character);
    };
}