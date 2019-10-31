#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	class ConsoleScene
		:private ConsoleObject
	{
	private:
		std::vector<ConsoleObject*> objectList;

	public:
		ConsoleScene();
		ConsoleScene(ConsoleScene& Scene);
		ConsoleScene(ConsoleScene&& Scene);
		const ConsoleScene& operator=(const ConsoleScene& Scene);

		//	add
		ConsoleScene& addObject(ConsoleObject* newObject);

		//	others
		const ConsoleScene& updateState();
		const ConsoleScene& render()const;
	};
}