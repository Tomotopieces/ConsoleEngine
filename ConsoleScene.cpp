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

ConsoleScene* ConsoleEngine::ConsoleScene::GetClone() const
{
	ConsoleScene* clone = new ConsoleScene(*this);
	return clone;
}

ConsoleScene& ConsoleScene::AddObject(const ConsoleObject& newObject)
{
	objectList.push_back(newObject.GetClone());
	return*this;
}

ConsoleScene& ConsoleEngine::ConsoleScene::AddObject(const ConsoleObject& newObject, const ConsolePoint2D Position)
{
	ConsoleObject* clone = newObject.GetClone();
	clone->SetPosition(Position);
	objectList.push_back(clone);
	return*this;
}

ConsoleScene& ConsoleEngine::ConsoleScene::AddObject(const ConsoleObject& newObject, const int x, const int y)
{
	ConsoleObject* clone = newObject.GetClone();
	clone->SetPosition(x, y);
	objectList.push_back(clone);
	return*this;
}

const ConsoleScene& ConsoleScene::UpdateState()
{
	if (objectList.size() == 0)
		return*this;
	for (ConsoleObject* object : objectList) {
		ConsoleButton* button = dynamic_cast<ConsoleButton*>(object);
		if(button != nullptr)
			button->UpdateState();
	}
	return*this;
}

const ConsoleScene& ConsoleScene::Render() const
{
	if (objectList.size() == 0)
		return*this;
	for (const ConsoleObject* object : objectList)
		object->Render();
	return*this;
}
