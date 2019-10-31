#include "ConsoleImage.h"
#include <iostream>
using namespace ConsoleEngine;
using namespace ConsoleController;

ConsoleImage::ConsoleImage(const std::vector<std::string> rawImage)
	: ConsoleObject("")
{
	image.resize(rawImage.size());
	for (int row = 0; row < rawImage.size(); ++row) {
		for (int column = 0; column < rawImage[row].size(); ++column) {
			image[row].push_back(rawImage[row][column]);
		}
	}
}

ConsoleEngine::ConsoleImage::ConsoleImage(const std::vector<std::string> rawImage, const ConsolePoint2D Position)
	: ConsoleObject("", Position)
{
	ConsoleImage(rawImage);
}

ConsoleEngine::ConsoleImage::ConsoleImage(const std::vector<std::string> rawImage, const int x, const int y)
	: ConsoleObject("", x, y)
{
	ConsoleImage(rawImage);
}

ConsoleImage::ConsoleImage(const ConsoleImage& Image)
	: ConsoleObject("")
	, image(Image.image)
{
}

ConsoleImage::ConsoleImage(ConsoleImage&& Image)
	: ConsoleObject("")
	, image(Image.image)
{
	Image.~ConsoleImage();
}

const ConsoleImage& ConsoleImage::operator=(const ConsoleImage& Image)
{
	if (this == &Image)
		return*this;
	ConsoleObject::operator=(Image);
	image = Image.image;
	return*this;
}

const int ConsoleImage::getBackColor(const ConsolePoint2D characterPosition)const
{
	return image[characterPosition.getX()][characterPosition.getY()].getBackColor();
}

const int ConsoleImage::getBackColor(const int x, const int y)const
{
	return image[x][y].getBackColor();
}

const int ConsoleImage::getForeColor(const ConsolePoint2D characterPosition)const
{
	return image[characterPosition.getX()][characterPosition.getY()].getForeColor();
}

const int ConsoleImage::getForeColor(const int x, const int y)const
{
	return image[x][y].getForeColor();
}

ConsoleImage& ConsoleImage::setCharacter(const ConsolePoint2D characterPosition, const char newcharacter)
{
	image[characterPosition.getX()][characterPosition.getY()].setCharacter(newcharacter);
	return*this;
}

ConsoleImage& ConsoleImage::setCharacter(const int x, const int y, const char newcharacter)
{
	image[x][y].setCharacter(newcharacter);
	return*this;
}

ConsoleImage& ConsoleImage::setColor(const ConsolePoint2D characterPosition, const int newBackColor, const int newForeColor)
{
	image[characterPosition.getX()][characterPosition.getY()].setBackColor(newBackColor).setForeColor(newForeColor);
	return*this;
}

ConsoleImage& ConsoleImage::setColor(const int x, const int y, const int newBackColor, const int newForeColor)
{
	image[x][y].setBackColor(newBackColor).setForeColor(newForeColor);
	return*this;
}

ConsoleImage& ConsoleImage::setAllColor(const int newBackColor, const int newForeColor)
{
	for (std::vector<ConsoleCharacter>& row : image) {
		for (ConsoleCharacter& character : row) {
			character.setBackColor(newBackColor);
			character.setForeColor(newForeColor);
		}
	}
	return*this;
}

const ConsoleImage& ConsoleImage::render() const
{
	//	do not use Character's render method
	ConsolePoint2D currentPosition = position;
	for (std::vector<ConsoleCharacter> row : image) {
		for (ConsoleCharacter character : row) {
			if (character.getCharacter() != '$') {
				Character.setBackColor(character.getBackColor());
				Character.setForeColor(character.getForeColor());
				Cursor.setPosition(currentPosition);
				std::cout << character.getCharacter();
			}
			currentPosition.reSet(currentPosition.getX() + 1, currentPosition.getY());
		}
		currentPosition.reSet(position.getX(), currentPosition.getY() + 1);
	}
	return*this;
}

const ConsoleImage& ConsoleEngine::ConsoleImage::render(const ConsolePoint2D startPosition) const
{
	//	do not use Character's render method
	ConsolePoint2D currentPosition = position;
	for (std::vector<ConsoleCharacter> row : image) {
		for (ConsoleCharacter character : row) {
			if (character.getCharacter() != '$') {
				Character.setBackColor(character.getBackColor());
				Character.setForeColor(character.getForeColor());
				Cursor.setPosition(currentPosition);
				std::cout << character.getCharacter();
			}
			currentPosition.reSet(currentPosition.getX() + 1, currentPosition.getY());
		}
		currentPosition.reSet(position.getX(), currentPosition.getY() + 1);
	}
	return*this;
}

const ConsoleImage& ConsoleEngine::ConsoleImage::render(const int x, int y) const
{
	return render(ConsolePoint2D(x, y));
}
