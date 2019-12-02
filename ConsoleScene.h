#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace console_engine
{
    class ConsoleScene
        : private ConsoleObject
    {
    private:
        std::vector<ConsoleObject*> _objectList;
    public:
        //  constructor
        ConsoleScene();
        ConsoleScene(const ConsoleScene& scene);
        ConsoleScene(ConsoleScene&& scene);
        const ConsoleScene& operator=(const ConsoleScene& scene);

        //  get
        virtual ConsoleScene* GetClone()const override;
        //  modifiable get element
        ConsoleObject* operator[](const int number);

        //  add
        ConsoleScene& AddObject(const ConsoleObject& object);
        ConsoleScene& AddObject(
            const ConsoleObject& object,
            const ConsolePoint2D position
        );
        ConsoleScene& AddObject(const ConsoleObject& object,
            const int x,
            const int y
        );

        //  others
        const ConsoleScene& UpdateState();
        const ConsoleScene& Render()const override;
    };
}