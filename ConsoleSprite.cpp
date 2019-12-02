#include "ConsoleSprite.h"
using namespace console_engine;

ConsoleSprite::ConsoleSprite(const RawImage& image)
    : ConsoleObject("")
    , _image(image)
{
}

ConsoleSprite::ConsoleSprite(
    const RawImage& image,
    const ConsolePoint2D& position
)
    : ConsoleObject("", position)
    , _image(image)
{
    _image.SetPosition(position);
}

ConsoleSprite::ConsoleSprite(const RawImage& image, const int x, const int y)
    : ConsoleObject("", x, y)
    , _image(image)
{
    _image.SetPosition(x, y);
}

ConsoleSprite::ConsoleSprite(const ConsoleImage& image)
    : ConsoleObject("")
    , _image(image)
{
}

ConsoleSprite::ConsoleSprite(ConsoleImage&& image)
    : ConsoleObject("")
    , _image(image)
{
    image.~ConsoleImage();
}

const ConsoleSprite& ConsoleSprite::operator=(const ConsoleImage& image)
{    // do not change "isTrigger" and "collider"
    ConsoleObject::operator=(image);
    _image = image;
    return*this;
}

ConsoleSprite::ConsoleSprite(const ConsoleSprite& sprite)
    : ConsoleObject(sprite)
    ,_image(sprite._image)
    , _isTrigger(sprite._isTrigger)
    , _collider(sprite._collider)
{
}

ConsoleSprite::ConsoleSprite(ConsoleSprite&& sprite)
    : ConsoleObject(sprite)
    , _image(sprite._image)
    , _isTrigger(sprite._isTrigger)
    , _collider(sprite._collider)
{
    sprite.~ConsoleSprite();
}

const ConsoleSprite& ConsoleSprite::operator=(const ConsoleSprite& sprite)
{
    ConsoleObject::operator=(sprite);
    _image = sprite._image;
    _isTrigger = sprite._isTrigger;
    _collider = sprite._collider;
    return*this;
}

ConsoleSprite* ConsoleSprite::GetClone() const
{
    ConsoleSprite* clone = new ConsoleSprite(*this);
    return clone;
}

const ConsoleImage& ConsoleSprite::GetImage() const
{
    return _image;
}

const bool ConsoleSprite::IsTrigger() const
{
    return _isTrigger;
}

const int ConsoleSprite::GetColliderWidth() const
{
    return _collider.width;
}

const int ConsoleSprite::GetColliderHeight() const
{
    return _collider.height;
}

const ConsolePoint2D& ConsoleSprite::GetColliderStartPoint() const
{
    return _collider.upperLeft;
}

ConsoleSprite& ConsoleSprite::SetImgae(const ConsoleImage& image)
{
    _image = image;
    return*this;
}

ConsoleSprite& ConsoleSprite::SetIsTrigger(const bool isTrigger)
{
    _isTrigger = isTrigger;
    return*this;
}

ConsoleSprite& ConsoleSprite::SetColliderWidth(const int width)
{
    _collider.width = width;
    return*this;
}

ConsoleSprite& ConsoleSprite::SetColliderHeight(const int height)
{
    _collider.height = height;
    return*this;
}

ConsoleSprite& ConsoleSprite::SetColliderStartPoint(const ConsolePoint2D& point)
{
    _collider.upperLeft = point;
    return*this;
}

const ConsoleSprite& ConsoleSprite::Render() const
{
    _image.Render();
    return*this;
}

