#pragma once
#ifdef CONSOLECONTROLLER_EXPORTS
#define CONSOLECONTROLLER_API __declspec(dllexport)	//此处为导出export
#else
#define CONSOLECONTROLLER_API __declspec(dllimport)	//此处为导入import
#endif

#include <Windows.h>

//****************************************
//****************************************

namespace  ConsoleController {
	//蓝，绿，红，加亮
	enum ConsoleColor { black = 0, blue = 1, green = 2, cyan = 3, red = 4, purple = 5, yellow = 6, white = 7, light = 8 };

	class CONSOLECONTROLLER_API MOUSE {
	public:
		MOUSE();

		/* 获取光标位置 */
		static COORD getPosition();
		/* 左键按下 */
		static bool leftDown();
		/* 右键按下 */
		static bool rightDown();
		/* 左右键同时按下 */
		static bool bothDown();
	};
	CONSOLECONTROLLER_API extern MOUSE Mouse;

	class CONSOLECONTROLLER_API CURSOR {
	public:
		CURSOR();

		/* 隐藏光标 */
		static bool hide();
		/* 显示光标 */
		static bool show();
		/* 设置光标位置(x, y) */
		static bool setPosition(short x, short y);
		/* 设置光标位置(COORD) */
		static bool setPosition(COORD pos);
	};
	CONSOLECONTROLLER_API extern CURSOR Cursor;

	class CONSOLECONTROLLER_API SCREEN {
	public:
		SCREEN();

		/* 获取窗口尺寸 */
		static const COORD getSize();
		/* 设置标题 */
		static bool setTitle(const char* str);
		/* 隐藏滚动条 */
		static bool hideScrollBar();
		/* 全屏化 */
		static bool fullScreen();
		/* 窗口化 */
		static bool window();
		/* 设置窗口尺寸 */
		static bool setSize(short width, short height);
		/* 设置背景颜色 */
		static bool setBackgroundColor(ConsoleColor color);
		static bool setBackgroundColor(int color);
		/* 清空窗口区域 */
		static bool clean();
	};
	CONSOLECONTROLLER_API extern SCREEN Screen;

	class CONSOLECONTROLLER_API CHARACTER {
	public:
		CHARACTER();

		/* 设置前景颜色 */
		static bool setForeColor(ConsoleColor color);
		static bool setForeColor(int color);
		/* 设置背景颜色 */
		static bool setBackColor(ConsoleColor color);
		static bool setBackColor(int color);
	};
	CONSOLECONTROLLER_API extern CHARACTER Character;
}