#pragma once
#include <Windows.h>

namespace  ConsoleController {
	enum ConsoleColor { black = 0, blue = 1, green = 2, cyan = 3, red = 4, purple = 5, yellow = 6, white = 7, light = 8 };

	class MOUSE {
	private:
		static HANDLE handle;
		static DWORD numRead;
		static INPUT_RECORD inrc;
	public:
		MOUSE();

		static COORD getPosition();
		static bool leftDown();
		static bool rightDown();
		static bool bothDown();
	};
	extern MOUSE Mouse;

	class CURSOR {
	private:
		static HANDLE handle;
		static CONSOLE_CURSOR_INFO CursorInfo;
		static COORD coord;
	public:
		CURSOR();

		static bool hide();
		static bool show();
		static bool setPosition(short x, short y);
		static bool setPosition(COORD pos);
	};
	extern CURSOR Cursor;

	class SCREEN {
	private:
		static HANDLE handle;
		static CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
		static SMALL_RECT rect;
		static COORD coord;

		static int backgroundColor;
	public:
		SCREEN();

		static const COORD getSize();
		static bool setTitle(const char* str);
		static bool hideScrollBar();
		static bool fullScreen();	//	can not support Windows7
		static bool window();
		static bool setSize(short width, short height);
		static int getBackgroundColor();
		static bool setBackgroundColor(ConsoleColor color);
		static bool setBackgroundColor(int color);
		static bool clean();
	};
	extern SCREEN Screen;

	class CHARACTER {
	private:
		static HANDLE handle;
		static int currentColor;
	public:
		CHARACTER();

		static int getForeColor();
		static int getBackColor();
		static bool setForeColor(ConsoleColor color);
		static bool setForeColor(int color);
		static bool setBackColor(ConsoleColor color);
		static bool setBackColor(int color);
	};
	extern CHARACTER Character;
}