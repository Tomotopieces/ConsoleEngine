#pragma once
#ifdef CONSOLEFUNC_EXPORTS
#define CONSOLEFUNC_API __declspec(dllexport)	//�˴�Ϊ����export
#else
#define CONSOLEFUNC_API __declspec(dllimport)	//�˴�Ϊ����import
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

		/* ��ȡ���λ�� */
		static COORD getPosition();
		/* ������� */
		static bool leftDown();
		/* �Ҽ����� */
		static bool rightDown();
		/* ���Ҽ�ͬʱ���� */
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

		/* ���ع�� */
		static bool hide();
		/* ��ʾ��� */
		static bool show();
		/* ���ù��λ��(x, y) */
		static bool setPosition(short x, short y);
		/* ���ù��λ��(COORD) */
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

		/* ���ñ��� */
		static bool setTitle(const char* str);
		/* ���ع����� */
		static bool hideScrollBar();
		/* ȫ���� */
		static bool fullScreen();
		/* ���ڻ� */
		static bool window();
		/* ���ô��ڳߴ� */
		static bool setSize(short width, short height);
	};

	//****************************************
	//****************************************

	CONSOLEFUNC_API extern SCREEN Screen;

	//�����̣��죬����
	const static enum Color { blue = 1, green = 2, cyan = 3, red = 4, purple = 5, yellow = 6, white = 7, light = 8 };

	static class CONSOLEFUNC_API CHARACTER {
	private:
		static HANDLE handle;
		static int currentColor;
	public:
		CHARACTER();

		/* ����ǰ����ɫ */
		static bool setForeColor(Color color);
		static bool setForeColor(int color);
		/* ���ñ�����ɫ */
		static bool setBackColor(Color color);
		static bool setBackColor(int color);
	};

	CONSOLEFUNC_API extern CHARACTER Character;

	//****************************************
	//****************************************
}