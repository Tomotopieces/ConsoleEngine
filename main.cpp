#include "ConsoleEngine.h"
#include <string>
using namespace ConsoleEngine;

int main() {
	Screen.SetTitle("Title");
	Screen.SetSize(128, 36);
	Screen.HideScrollBar();
	auto temp = Screen.SetBackgroundColor(light);
	Screen.Clean();
	Cursor.Hide();

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
	enemy.SetAllColor(light, black);
	cScene.AddObject(enemy, 10, 10);
	cScene.AddObject(enemy, 20, 10);
	cScene.AddObject(enemy, 30, 10);

	while (true)
		cScene.UpdateState().Render();
	return 0;
}