#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	class ConsoleScene
		: private ConsoleObject
		, private ObjectInterface
	{
	private:
		std::vector<ConsoleObject*> objectList;

	public:
		//	constructor
		ConsoleScene();
		ConsoleScene(const ConsoleScene& Scene);
		ConsoleScene(ConsoleScene&& Scene);
		const ConsoleScene& operator=(const ConsoleScene& Scene);

		//	get
		ConsoleScene* getClone()const override;

		//	add
		ConsoleScene& addObject(ConsoleObject& newObject);
		ConsoleScene& addObject(ConsoleObject& newObject, const ConsolePoint2D Position);
		ConsoleScene& addObject(ConsoleObject& newObject, const int x, const int y);

		//	others
		const ConsoleScene& updateState();
		const ConsoleScene& render()const;
	};
}