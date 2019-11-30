#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	class ConsoleScene
		: private ConsoleObject
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
		virtual ConsoleScene* GetClone()const override;

		//	add
		ConsoleScene& AddObject(const ConsoleObject& newObject);
		ConsoleScene& AddObject(const ConsoleObject& newObject, const ConsolePoint2D Position);
		ConsoleScene& AddObject(const ConsoleObject& newObject, const int x, const int y);

		//	others
		const ConsoleScene& UpdateState();
		const ConsoleScene& Render()const override;
	};
}