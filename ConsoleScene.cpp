#include "ConsoleScene.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
using namespace console_engine;
using namespace consolr_controller;

ConsoleScene::ConsoleScene()
    : ConsoleObject("")
{
}

ConsoleScene::ConsoleScene(const ConsoleScene& scene)
    : ConsoleObject("")
    , _objectList(scene._objectList)
{
}

ConsoleScene::ConsoleScene(ConsoleScene&& scene)
    : ConsoleObject("")
    , _objectList(scene._objectList)
{
    scene.~ConsoleScene();
}

const ConsoleScene& ConsoleScene::operator=(const ConsoleScene& scene)
{
    if(this == &scene)
        return*this;
    ConsoleObject::operator=(scene);
    _objectList = scene._objectList;
    return*this;
}

ConsoleScene* ConsoleScene::GetClone() const
{
    ConsoleScene* clone = new ConsoleScene(*this);
    return clone;
}

ConsoleObject* ConsoleScene::operator[](const int number)
{
    if(number < _objectList.size())
        return _objectList[number];
    return nullptr;
}

ConsoleScene& ConsoleScene::AddObject(const ConsoleObject& object)
{
    _objectList.push_back(object.GetClone());
    return*this;
}

ConsoleScene& ConsoleScene::AddObject(const ConsoleObject& object, const ConsolePoint2D position)
{
    ConsoleObject* clone = object.GetClone();
    clone->SetPosition(position);
    _objectList.push_back(clone);
    return*this;
}

ConsoleScene& ConsoleScene::AddObject(const ConsoleObject& object, const int x, const int y)
{
    ConsoleObject* clone = object.GetClone();
    clone->SetPosition(x, y);
    _objectList.push_back(clone);
    return*this;
}

const ConsoleScene& ConsoleScene::UpdateState()
{
    if (_objectList.size() == 0)
        return*this;
    for (ConsoleObject* object : _objectList) {
        ConsoleButton* button = dynamic_cast<ConsoleButton*>(object);
        if(button != nullptr)
            button->UpdateState();
    }
    return*this;
}

const ConsoleScene& ConsoleScene::Render() const
{
    if (_objectList.size() == 0)
        return*this;
    for (const ConsoleObject* object : _objectList)
        object->Render();
    return*this;
}
