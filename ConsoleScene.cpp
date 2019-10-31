#include "ConsoleScene.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
using namespace ConsoleEngine;
using namespace ConsoleController;

ConsoleScene::ConsoleScene()
	: ConsoleObject("")
{
}

ConsoleScene::ConsoleScene(ConsoleScene& Scene)
	: ConsoleObject("")
	, objectList(Scene.objectList)
{
}

ConsoleScene::ConsoleScene(ConsoleScene&& Scene)
	: ConsoleObject("")
	, objectList(Scene.objectList)
{
	Scene.~ConsoleScene();
}

const ConsoleScene& ConsoleScene::operator=(const ConsoleScene& Scene)
{
	if(this == &Scene)
		return*this;
	ConsoleObject::operator=(Scene);
	objectList = Scene.objectList;
	return*this;
}

ConsoleScene& ConsoleScene::addObject(ConsoleObject* newObject)
{
	objectList.push_back(newObject);
	return*this;
}

const ConsoleScene& ConsoleScene::updateState()
{
	if (objectList.size() == 0)
		return*this;
	for (ConsoleObject* pObject : objectList) {
		ConsoleButton* pButton = dynamic_cast<ConsoleButton*>(pObject);
		if (pButton != nullptr)
			pButton->updateState();
	}
	return*this;
}

const ConsoleScene& ConsoleScene::render() const
{
	if (objectList.size() == 0)
		return*this;
	for (ConsoleObject* pObject : objectList)
		pObject->render();
	return*this;
}
