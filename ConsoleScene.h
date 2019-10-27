#include "ConsoleFunc.h"
#include "ConsoleButton.h"
#include "ConsoleText.h"
#include <vector>

class ConsoleScene
{
private:
	std::vector<ConsoleObject*> objectList;
public:
	ConsoleScene();
	ConsoleScene(ConsoleScene& scene2);
	ConsoleScene(ConsoleScene&& scene2);

	ConsoleScene& addObject(ConsoleObject* newObject);

	const ConsoleScene& updateState();
	const ConsoleScene& render()const;
};