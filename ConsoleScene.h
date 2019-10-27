#pragma once
#include "ConsoleObject.h"
#include <vector>

class ConsoleScene	//����̨����
{
private:
	std::vector<ConsoleObject*> objectList;	//���������幹��

public:
	ConsoleScene();
	ConsoleScene(ConsoleScene& scene2);
	ConsoleScene(ConsoleScene&& scene2);

	ConsoleScene& addObject(ConsoleObject* newObject);

	const ConsoleScene& updateState();
	const ConsoleScene& render()const;
};