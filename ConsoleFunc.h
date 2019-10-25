#pragma once
#ifdef CONSOLEFUNC_EXPORTS
#define CONSOLEFUNC_API __declspec(dllexport)	//此处为导出export
#else
#define CONSOLEFUNC_API __declspec(dllimport)	//此处为导入import
#endif

#include<Windows.h>

//****************************************
//****************************************

namespace  ConsoleFunction {

	//****************************************
	//****************************************

	static class CONSOLEFUNC_API MOUSE {
	private:
		static HANDLE handle;
		static DWORD numRead;
		static INPUT_RECORD inrc;
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

	CONSOLEFUNC_API extern MOUSE Mouse;

	//****************************************
	//****************************************

	static class CONSOLEFUNC_API CURSOR {
	private:
		static HANDLE handle;
		static CONSOLE_CURSOR_INFO CursorInfo;
		static COORD coord;
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

	CONSOLEFUNC_API extern CURSOR Cursor;

	//****************************************
	//****************************************

	static class CONSOLEFUNC_API SCREEN {
	private:
		static HANDLE handle;
		static CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
		static SMALL_RECT rect;
		static COORD coord;
	public:
		SCREEN();

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
	};

	//****************************************
	//****************************************

	CONSOLEFUNC_API extern SCREEN Screen;

	//蓝，绿，红，加亮
	const static enum Color { blue = 1, green = 2, cyan = 3, red = 4, purple = 5, yellow = 6, white = 7, light = 8 };

	static class CONSOLEFUNC_API CHARACTER {
	private:
		static HANDLE handle;
		static int currentColor;
	public:
		CHARACTER();

		/* 设置前景颜色 */
		static bool setForeColor(Color color);
		static bool setForeColor(int color);
		/* 设置背景颜色 */
		static bool setBackColor(Color color);
		static bool setBackColor(int color);
	};

	CONSOLEFUNC_API extern CHARACTER Character;

	//****************************************
	//****************************************
}