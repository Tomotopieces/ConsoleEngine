#include "ConsoleImage.h"
#include <iostream>

ConsoleImage::ConsoleImage(std::vector<std::string> rawImage)
	: ConsoleObject("")
{
	image.resize(rawImage.size());
	for (int row = 0; row < rawImage.size(); ++row) {
		for (int column = 0; column < rawImage[row].size(); ++column) {
			image[row].push_back(rawImage[row][column]);
		}
	}
}

ConsoleImage::ConsoleImage(const ConsoleImage& image2)
	: ConsoleObject("")
	, image(image2.image)
{
}

ConsoleImage::ConsoleImage(ConsoleImage&& image2)
	: ConsoleObject("")
	, image(image2.image)
{
	image2.~ConsoleImage();
}

const ConsoleImage& ConsoleImage::operator=(const ConsoleImage& image2)
{
	if (this == &image2)
		return*this;
	ConsoleObject::operator=(image2);
	image = image2.image;
	return*this;
}

const ConsoleImage& ConsoleImage::render() const
{
	ConsolePoint2D currentPosition = position;
	//将image的position作为偏移量
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
