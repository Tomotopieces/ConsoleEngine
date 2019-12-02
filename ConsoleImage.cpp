#include <iostream>
#include "ConsoleImage.h"
using namespace console_engine;
using namespace consolr_controller;

const void ConsoleImage::CopyFromRawImage(
    const RawImage& rawImage
)
{
    _image.resize(rawImage.size());
    for (int row = 0; row < rawImage.size(); ++row) {
        for (int column = 0; column < rawImage[row].size(); ++column) {
            _image[row].push_back(rawImage[row][column]);
        }
    }
}

ConsoleImage::ConsoleImage(const RawImage& rawImage)
    : ConsoleObject("")
{
    CopyFromRawImage(rawImage);
}

ConsoleImage::ConsoleImage(
    const RawImage& rawImage,
    const ConsolePoint2D position
)
    : ConsoleObject("", position)
{
    CopyFromRawImage(rawImage);
}

ConsoleImage::ConsoleImage(
    const RawImage& rawImage, const int x,
    const int y
)
    : ConsoleObject("", x, y)
{
    CopyFromRawImage(rawImage);
}

ConsoleImage::ConsoleImage(const ConsoleImage& image)
    : ConsoleObject("")
    , _image(image._image)
{
}

ConsoleImage::ConsoleImage(
    const ConsoleImage& image,
    const ConsolePoint2D position
)
    : ConsoleObject("")
    , _image(image._image)
{
    SetPosition(position);
}

ConsoleImage::ConsoleImage(
    const ConsoleImage& image,
    const int x,
    const int y
)
    : ConsoleObject("")
    , _image(image._image)
{
    SetPosition(x, y);
}

ConsoleImage::ConsoleImage(ConsoleImage&& image)
    : ConsoleObject("")
    , _image(image._image)
{
    image.~ConsoleImage();
}

const ConsoleImage& ConsoleImage::operator=(
    const RawImage& rawImage
    )
{
    CopyFromRawImage(rawImage);
    return*this;
}

const ConsoleImage& ConsoleImage::operator=(const ConsoleImage& Image)
{
    if (this == &Image)
        return*this;
    ConsoleObject::operator=(Image);
    _image = Image._image;
    return*this;
}

ConsoleImage* ConsoleImage::GetClone() const
{
    ConsoleImage* clone = new ConsoleImage(*this);
    return clone;
}

const int ConsoleImage::GetBackColor(
    const ConsolePoint2D position
)const
{
    return _image[position.GetX()][position.GetY()].GetBackColor();
}

const int ConsoleImage::GetBackColor(const int x, const int y)const
{
    return _image[x][y].GetBackColor();
}

const int ConsoleImage::GetForeColor(const ConsolePoint2D position)const
{
    return _image[position.GetX()][position.GetY()].GetForeColor();
}

const int ConsoleImage::GetForeColor(const int x, const int y)const
{
    return _image[x][y].GetForeColor();
}

ConsoleImage& ConsoleImage::SetCharacter(
    const ConsolePoint2D position,
    const char character
)
{
    _image[position.GetX()][position.GetY()].SetCharacter(character);
    return*this;
}

ConsoleImage& ConsoleImage::SetCharacter(
    const int x,
    const int y,
    const char character
)
{
    _image[x][y].SetCharacter(character);
    return*this;
}

ConsoleImage& ConsoleImage::SetColor(
    const ConsolePoint2D position,
    const int backColor,
    const int foreColor
)
{
    _image[position.GetX()][position.GetY()].SetBackColor(backColor).SetForeColor(foreColor);
    return*this;
}

ConsoleImage& ConsoleImage::SetColor(const int x, const int y, const int backColor, const int foreColor)
{
    _image[x][y].SetBackColor(backColor).SetForeColor(foreColor);
    return*this;
}

ConsoleImage& ConsoleImage::SetAllColor(const int backColor, const int foreColor)
{
    for (std::vector<ConsoleCharacter>& row : _image) {
        for (ConsoleCharacter& character : row) {
            character.SetBackColor(backColor);
            character.SetForeColor(foreColor);
        }
    }
    return*this;
}

const ConsoleImage& ConsoleImage::Render() const
{
    //  do not use Character's render method
    ConsolePoint2D currentPosition = GetPosition();
    for (std::vector<ConsoleCharacter> row : _image) {
        for (ConsoleCharacter character : row) {
            if (character.GetCharacter() != '$') {
                Character.SetBackColor(character.GetBackColor());
                Character.SetForeColor(character.GetForeColor());
                Cursor.SetPosition(currentPosition);
                std::cout << character.GetCharacter();
            }
            currentPosition.Set(currentPosition.GetX() + 1, currentPosition.GetY());
        }
        currentPosition.Set(GetPosition().GetX(), currentPosition.GetY() + 1);
    }
    return*this;
}

const ConsoleImage& ConsoleImage::Render(const ConsolePoint2D startPosition) const
{
    //  do not use Character's render method
    ConsolePoint2D currentPosition = GetPosition();
    for (std::vector<ConsoleCharacter> row : _image) {
        for (ConsoleCharacter character : row) {
            if (character.GetCharacter() != '$') {
                Character.SetBackColor(character.GetBackColor());
                Character.SetForeColor(character.GetForeColor());
                Cursor.SetPosition(currentPosition);
                std::cout << character.GetCharacter();
            }
            currentPosition.Set(currentPosition.GetX() + 1, currentPosition.GetY());
        }
        currentPosition.Set(GetPosition().GetX(), currentPosition.GetY() + 1);
    }
    return*this;
}

const ConsoleImage& ConsoleImage::Render(const int x, int y) const
{
    return Render(ConsolePoint2D(x, y));
}
