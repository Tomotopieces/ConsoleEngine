#pragma once
#include "ConsoleObject.h"
#include "ConsoleCharacter.h"
#include <vector>
#include <string>
using namespace ConsoleController;

class ConsoleImage
	: public ConsoleObject
{
private:
	std::vector<std::vector<ConsoleCharacter>> image;
	explicit ConsoleImage();
public:
	ConsoleImage(std::vector<std::string> rawImage);
	ConsoleImage(const ConsoleImage& image2);
	ConsoleImage(ConsoleImage&& image2);
	const ConsoleImage& operator=(const ConsoleImage& image2);

	virtual const ConsoleImage& render()const;	//»æÖÆ
};