#include "ConsoleImage.h"
#include <iostream>
using namespace ConsoleEngine;
using namespace ConsoleController;

const void ConsoleEngine::ConsoleImage::copyFromRawImage(const RawImage& rawImage)
{
	image.resize(rawImage.size());
	for (int row = 0; row < rawImage.size(); ++row) {
		for (int column = 0; column < rawImage[row].size(); ++column) {
			image[row].push_back(rawImage[row][column]);
		}
	}
}

ConsoleImage::ConsoleImage(const RawImage& rawImage)
	: ConsoleObject("")
{
	copyFromRawImage(rawImage);
}

ConsoleEngine::ConsoleImage::ConsoleImage(const RawImage& rawImage, const ConsolePoint2D Position)
	: ConsoleObject("", Position)
{
	copyFromRawImage(rawImage);
}

ConsoleEngine::ConsoleImage::ConsoleImage(const RawImage& rawImage, const int x, const int y)
	: ConsoleObject("", x, y)
{
	copyFromRawImage(rawImage);
}

ConsoleImage::ConsoleImage(const ConsoleImage& Image)
	: ConsoleObject("")
	, image(Image.image)
{
}

ConsoleEngine::ConsoleImage::ConsoleImage(const ConsoleImage& Image, const ConsolePoint2D Position)
	: ConsoleObject("")
	, image(Image.image)
{
	SetPosition(Position);
}

ConsoleEngine::ConsoleImage::ConsoleImage(const ConsoleImage& Image, const int x, const int y)
	: ConsoleObject("")
	, image(Image.image)
{
	SetPosition(x, y);
}

ConsoleImage::ConsoleImage(ConsoleImage&& Image)
	: ConsoleObject("")
	, image(Image.image)
{
	Image.~ConsoleImage();
}

const ConsoleImage& ConsoleEngine::ConsoleImage::operator=(const RawImage& rawImage)
{
	copyFromRawImage(rawImage);
	return*this;
}

const ConsoleImage& ConsoleImage::operator=(const ConsoleImage& Image)
{
	if (this == &Image)
		return*this;
	ConsoleObject::operator=(Image);
	image = Image.image;
	return*this;
}

ConsoleImage* ConsoleEngine::ConsoleImage::GetClone() const
{
	ConsoleImage* clone = new ConsoleImage(*this);
	return clone;
}

const int ConsoleImage::GetBackColor(const ConsolePoint2D characterPosition)const
{
	return image[characterPosition.GetX()][characterPosition.GetY()].GetBackColor();
}

const int ConsoleImage::GetBackColor(const int x, const int y)const
{
	return image[x][y].GetBackColor();
}

const int ConsoleImage::GetForeColor(const ConsolePoint2D characterPosition)const
{
	return image[characterPosition.GetX()][characterPosition.GetY()].GetForeColor();
}

const int ConsoleImage::GetForeColor(const int x, const int y)const
{
	return image[x][y].GetForeColor();
}

ConsoleImage& ConsoleImage::SetCharacter(const ConsolePoint2D characterPosition, const char newcharacter)
{
	image[characterPosition.GetX()][characterPosition.GetY()].SetCharacter(newcharacter);
	return*this;
}

ConsoleImage& ConsoleImage::SetCharacter(const int x, const int y, const char newcharacter)
{
	image[x][y].SetCharacter(newcharacter);
	return*this;
}

ConsoleImage& ConsoleImage::SetColor(const ConsolePoint2D characterPosition, const int newBackColor, const int newForeColor)
{
	image[characterPosition.GetX()][characterPosition.GetY()].SetBackColor(newBackColor).SetForeColor(newForeColor);
	return*this;
}

ConsoleImage& ConsoleImage::SetColor(const int x, const int y, const int newBackColor, const int newForeColor)
{
	image[x][y].SetBackColor(newBackColor).SetForeColor(newForeColor);
	return*this;
}

ConsoleImage& ConsoleImage::SetAllColor(const int newBackColor, const int newForeColor)
{
	for (std::vector<ConsoleCharacter>& row : image) {
		for (ConsoleCharacter& character : row) {
			character.SetBackColor(newBackColor);
			character.SetForeColor(newForeColor);
		}
	}
	return*this;
}

const ConsoleImage& ConsoleImage::Render() const
{
	//	do not use Character's render method
	ConsolePoint2D currentPosition = position;
	for (std::vector<ConsoleCharacter> row : image) {
		for (ConsoleCharacter character : row) {
			if (character.GetCharacter() != '$') {
				Character.SetBackColor(character.GetBackColor());
				Character.SetForeColor(character.GetForeColor());
				Cursor.SetPosition(currentPosition);
				std::cout << character.GetCharacter();
			}
			currentPosition.Set(currentPosition.GetX() + 1, currentPosition.GetY());
		}
		currentPosition.Set(position.GetX(), currentPosition.GetY() + 1);
	}
	return*this;
}

const ConsoleImage& ConsoleEngine::ConsoleImage::Render(const ConsolePoint2D startPosition) const
{
	//	do not use Character's render method
	ConsolePoint2D currentPosition = position;
	for (std::vector<ConsoleCharacter> row : image) {
		for (ConsoleCharacter character : row) {
			if (character.GetCharacter() != '$') {
				Character.SetBackColor(character.GetBackColor());
				Character.SetForeColor(character.GetForeColor());
				Cursor.SetPosition(currentPosition);
				std::cout << character.GetCharacter();
			}
			currentPosition.Set(currentPosition.GetX() + 1, currentPosition.GetY());
		}
		currentPosition.Set(position.GetX(), currentPosition.GetY() + 1);
	}
	return*this;
}

const ConsoleImage& ConsoleEngine::ConsoleImage::Render(const int x, int y) const
{
	return Render(ConsolePoint2D(x, y));
}
