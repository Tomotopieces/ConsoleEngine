#pragma once
#include <vector>
#include "ConsoleCharacter.h"

namespace console_engine
{
    //  vector of string.
    typedef std::vector<std::string> RawImage;

    class ConsoleImage
        : public ConsoleObject
    {
    private:
        std::vector<std::vector<ConsoleCharacter>> _image;

        //  others
        const void CopyFromRawImage(const RawImage& rawImage);

        explicit ConsoleImage();
    public:
        //  constructor
        ConsoleImage(const RawImage& rawImage);
        ConsoleImage(const RawImage& rawImage, const ConsolePoint2D position);
        ConsoleImage(const RawImage& rawImage, const int x, const int y);
        ConsoleImage(const ConsoleImage& image);
        ConsoleImage(const ConsoleImage& image, const ConsolePoint2D position);
        ConsoleImage(const ConsoleImage& image, const int x, const int y);
        ConsoleImage(ConsoleImage&& image);
        const ConsoleImage& operator=(const RawImage& rawImage);
        const ConsoleImage& operator=(const ConsoleImage& Image);

        //  get
        virtual ConsoleImage* GetClone()const override;
        const int GetBackColor(const ConsolePoint2D position)const;
        const int GetBackColor(const int x, const int y)const;
        const int GetForeColor(const ConsolePoint2D position)const;
        const int GetForeColor(const int x, const int y)const;

        //  set
        ConsoleImage& SetCharacter(
            const ConsolePoint2D position,
            const char character
        );
        ConsoleImage& SetCharacter(
            const int x,
            const int y,
            const char character
        );
        ConsoleImage& SetColor(
            const ConsolePoint2D position,
            const int backColor,
            const int foreColor
        );
        ConsoleImage& SetColor(
            const int x,
            const int y,
            const int backColor,
            const int foreColor
        );
        ConsoleImage& SetAllColor(
            const int backColor,
            const int foreColor
        );

        //  others
        virtual const ConsoleImage& Render()const override;
        const ConsoleImage& Render(const ConsolePoint2D startPosition)const;
        const ConsoleImage& Render(const int x, int y)const;
    };
}