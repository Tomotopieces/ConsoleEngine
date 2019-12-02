#pragma once
#include "ConsoleImage.h"

namespace console_engine
{
    class ConsoleSprite
        : public ConsoleObject
    {
    private:
        ConsoleImage _image;
        bool _isTrigger = false;
        struct ColliderState
        {
            int width = 1;
            int height = 1;
            ConsolePoint2D upperLeft = { 0,0 };
        };
        ColliderState _collider;
        explicit ConsoleSprite();
    public:
        //  construct by rawImage
        ConsoleSprite(const RawImage& image);
        ConsoleSprite(const RawImage& image, const ConsolePoint2D& position);
        ConsoleSprite(const RawImage& image, const int x, const int y);

        //  construct by ConsoleImage
        ConsoleSprite(const ConsoleImage& image);
        ConsoleSprite(ConsoleImage&& image);
        const ConsoleSprite& operator=(const ConsoleImage& image);

        //  construct by other Sprite
        ConsoleSprite(const ConsoleSprite& sprite);
        ConsoleSprite(ConsoleSprite&& sprite);
        const ConsoleSprite& operator=(const ConsoleSprite& sprite);

        //  get
        virtual ConsoleSprite* GetClone()const override;
        const ConsoleImage& GetImage()const;
        const bool IsTrigger()const;
        const int GetColliderWidth()const;
        const int GetColliderHeight()const;
        const ConsolePoint2D& GetColliderStartPoint()const;

        //  set
        ConsoleSprite& SetImgae(const ConsoleImage& image);
        ConsoleSprite& SetIsTrigger(const bool isTrigger);
        ConsoleSprite& SetColliderWidth(const int width);
        ConsoleSprite& SetColliderHeight(const int height);
        ConsoleSprite& SetColliderStartPoint(const ConsolePoint2D& point);

        //  others
        const ConsoleSprite& Render()const override;
    };
}