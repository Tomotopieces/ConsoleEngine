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

		static COORD GetPosition();
		static bool GetLeftDown();
		static bool GetRightDown();
		static bool GetBothDown();
	};
	extern MOUSE Mouse;

	class CURSOR {
	private:
		static HANDLE handle;
		static CONSOLE_CURSOR_INFO CursorInfo;
		static COORD coord;
	public:
		CURSOR();

		static bool Hide();
		static bool Show();
		static bool SetPosition(short x, short y);
		static bool SetPosition(COORD pos);
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

		static const COORD GetSize();
		static bool SetTitle(const char* str);
		static bool HideScrollBar();
		static bool FullScreen();	//	can not support Windows7
		static bool Window();
		static bool SetSize(short width, short height);
		static int GetBackgroundColor();
		static bool SetBackgroundColor(ConsoleColor color);
		static bool SetBackgroundColor(int color);
		static bool Clean();
	};
	extern SCREEN Screen;

	class CHARACTER {
	private:
		static HANDLE handle;
		static int currentColor;
	public:
		CHARACTER();

		static int GetForeColor();
		static int GetBackColor();
		static bool SetForeColor(ConsoleColor color);
		static bool SetForeColor(int color);
		static bool SetBackColor(ConsoleColor color);
		static bool SetBackColor(int color);
	};
	extern CHARACTER Character;
}