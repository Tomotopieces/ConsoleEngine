#pragma once
#include "ConsoleObject.h"
#include <vector>

class ConsoleScene	//控制台场景
{
private:
	std::vector<ConsoleObject*> objectList;	//场景由物体构成

public:
	ConsoleScene();
	ConsoleScene(ConsoleScene& scene2);
	ConsoleScene(ConsoleScene&& scene2);

	ConsoleScene& addObject(ConsoleObject* newObject);

	const ConsoleScene& updateState();
	const ConsoleScene& render()const;
};