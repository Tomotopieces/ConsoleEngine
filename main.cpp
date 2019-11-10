#include "ConsoleEngine.h"
#include <string>
using namespace ConsoleEngine;

int main() {
	Screen.setTitle("Title");
	Screen.setSize(128, 36);
	Screen.hideScrollBar();
	auto temp = Screen.setBackgroundColor(light);
	Screen.clean();
	Cursor.hide();

	ConsoleScene cScene;

	/*
	//http://patorjk.com/software/taag/#p=display&f=Big&t=Sky%20Fighter
	RawImage title =
	{
		"                                                        ",
		"   _____ _            ______ _       _     _            ",
		"  / ____| |          |  ____(_)     | |   | |           ",
		" | (___ | | ___   _  | |__   _  __ _| |__ | |_ ___ _ __ ",
		"  \\___ \\| |/ / | | | |  __| | |/ _` | '_ \\| __/ _ \\ '__|",
		"  ____) |   <| |_| | | |    | | (_| | | | | ||  __/ |   ",
		" |_____/|_|\\_\\\\__, | |_|    |_|\\__, |_| |_|\\__\\___|_|   ",
		"               __/ |            __/ |                   ",
		"              |___/            |___/                    ",
		"                                                        "
	};
	ConsoleImage cTitle(title, 36, 8);
	cTitle.setAllColor(white, black);
	cScene.addObject(&cTitle);
	*/

	RawImage enemyImage=
	{
		"\\ /",
		" T ",
		" V "
	};
	ConsoleImage enemy(enemyImage);
	enemy.setAllColor(light, black);
	cScene.addObject(enemy, 10, 10);
	cScene.addObject(enemy, 20, 10);
	cScene.addObject(enemy, 30, 10);

	while (true)
		cScene.updateState().render();
	return 0;
}