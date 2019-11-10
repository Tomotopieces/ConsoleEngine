#include "ConsoleScene.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
using namespace ConsoleEngine;
using namespace ConsoleController;

ConsoleScene::ConsoleScene()
	: ConsoleObject("")
{
}

ConsoleScene::ConsoleScene(const ConsoleScene& Scene)
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

ConsoleScene* ConsoleEngine::ConsoleScene::getClone() const
{
	ConsoleScene* clone = new ConsoleScene(*this);
	return clone;
}

ConsoleScene& ConsoleScene::addObject(ConsoleObject& newObject)
{
	objectList.push_back(newObject.getClone());
	return*this;
}

ConsoleScene& ConsoleEngine::ConsoleScene::addObject(ConsoleObject& newObject, const ConsolePoint2D Position)
{
	ConsoleObject* clone = newObject.getClone();
	clone->setPosition(Position);
	objectList.push_back(clone);
	return*this;
}

ConsoleScene& ConsoleEngine::ConsoleScene::addObject(ConsoleObject& newObject, const int x, const int y)
{
	ConsoleObject* clone = newObject.getClone();
	clone->setPosition(x, y);
	objectList.push_back(clone);
	return*this;
}

const ConsoleScene& ConsoleScene::updateState()
{
	if (objectList.size() == 0)
		return*this;
	for (ConsoleObject* object : objectList) {
		ConsoleButton* button = dynamic_cast<ConsoleButton*>(object);
		if(button != nullptr)
			button->updateState();
	}
	return*this;
}

const ConsoleScene& ConsoleScene::render() const
{
	if (objectList.size() == 0)
		return*this;
	for (const ConsoleObject* object : objectList)
		object->render();
	return*this;
}
