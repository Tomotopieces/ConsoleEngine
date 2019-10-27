#include "ConsoleScene.h"
#include <typeinfo>

ConsoleScene::ConsoleScene()
{
}

ConsoleScene::ConsoleScene(ConsoleScene& scene2)
	: objectList(scene2.objectList)
{
}

ConsoleScene::ConsoleScene(ConsoleScene&& scene2)
	: objectList(scene2.objectList)
{
	scene2.~ConsoleScene();
}

ConsoleScene& ConsoleScene::addObject(ConsoleObject* newObject)
{
	objectList.push_back(newObject);
	return*this;
}

const ConsoleScene& ConsoleScene::updateState()
{
	for (ConsoleObject* pObject : objectList) {
		ConsoleButton* pButton = dynamic_cast<ConsoleButton*>(pObject);
		if (pButton != nullptr)
			pButton->updateState();
	}
	return*this;
}

const ConsoleScene& ConsoleScene::render() const
{
	for (ConsoleObject* pObject : objectList)
		pObject->render();
	return*this;
}
