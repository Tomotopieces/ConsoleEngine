#pragma once
#ifdef CONSOLECONTROLLER_EXPORTS
#define CONSOLECONTROLLER_API __declspec(dllexport)	//�˴�Ϊ����export
#else
#define CONSOLECONTROLLER_API __declspec(dllimport)	//�˴�Ϊ����import
#endif

#include <Windows.h>

//****************************************
//****************************************

namespace  ConsoleController {
	//�����̣��죬����
	enum ConsoleColor { black = 0, blue = 1, green = 2, cyan = 3, red = 4, purple = 5, yellow = 6, white = 7, light = 8 };

	class CONSOLECONTROLLER_API MOUSE {
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
	CONSOLECONTROLLER_API extern MOUSE Mouse;

	class CONSOLECONTROLLER_API CURSOR {
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
	CONSOLECONTROLLER_API extern CURSOR Cursor;

	class CONSOLECONTROLLER_API SCREEN {
	public:
		SCREEN();

		/* ��ȡ���ڳߴ� */
		static const COORD getSize();
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
		/* ���ñ�����ɫ */
		static bool setBackgroundColor(ConsoleColor color);
		static bool setBackgroundColor(int color);
		/* ��մ������� */
		static bool clean();
	};
	CONSOLECONTROLLER_API extern SCREEN Screen;

	class CONSOLECONTROLLER_API CHARACTER {
	public:
		CHARACTER();

		/* ����ǰ����ɫ */
		static bool setForeColor(ConsoleColor color);
		static bool setForeColor(int color);
		/* ���ñ�����ɫ */
		static bool setBackColor(ConsoleColor color);
		static bool setBackColor(int color);
	};
	CONSOLECONTROLLER_API extern CHARACTER Character;
}