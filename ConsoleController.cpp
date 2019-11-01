#include "ConsoleController.h"

HANDLE ConsoleController::MOUSE::handle = *(new HANDLE);
DWORD ConsoleController::MOUSE::numRead = *(new DWORD);
INPUT_RECORD ConsoleController::MOUSE::inrc = *(new INPUT_RECORD);

ConsoleController::MOUSE::MOUSE()
{
	handle = GetStdHandle(STD_INPUT_HANDLE);
}

COORD ConsoleController::MOUSE::getPosition()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwMousePosition;
}

bool ConsoleController::MOUSE::leftDown()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
}

bool ConsoleController::MOUSE::rightDown()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED;
}

bool ConsoleController::MOUSE::bothDown()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwButtonState == (FROM_LEFT_1ST_BUTTON_PRESSED + RIGHTMOST_BUTTON_PRESSED);
}

ConsoleController::MOUSE Mouse;

//****************************************
//****************************************

HANDLE ConsoleController::CURSOR::handle = *(new HANDLE);
CONSOLE_CURSOR_INFO ConsoleController::CURSOR::CursorInfo = *(new CONSOLE_CURSOR_INFO);
COORD ConsoleController::CURSOR::coord = *(new COORD);

ConsoleController::CURSOR::CURSOR()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(handle, &CursorInfo);
}

bool ConsoleController::CURSOR::hide()
{
	CursorInfo.bVisible = false;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool ConsoleController::CURSOR::show()
{
	CursorInfo.bVisible = true;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool ConsoleController::CURSOR::setPosition(short x, short y)
{
	coord = { x,y };
	return SetConsoleCursorPosition(handle, coord);
}

bool ConsoleController::CURSOR::setPosition(COORD pos)
{
	coord = pos;
	return SetConsoleCursorPosition(handle, coord);
}

ConsoleController::CURSOR Cursor;

//****************************************
//****************************************

HANDLE ConsoleController::SCREEN::handle = *(new HANDLE);
CONSOLE_SCREEN_BUFFER_INFO ConsoleController::SCREEN::screenBufferInfo = *(new CONSOLE_SCREEN_BUFFER_INFO);
SMALL_RECT ConsoleController::SCREEN::rect = *(new SMALL_RECT);
COORD ConsoleController::SCREEN::coord = *(new COORD);
int ConsoleController::SCREEN::backgroundColor = ConsoleController::black;

ConsoleController::SCREEN::SCREEN()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &screenBufferInfo);
	rect = screenBufferInfo.srWindow;
}

const COORD ConsoleController::SCREEN::getSize()
{
	GetConsoleScreenBufferInfo(handle, &screenBufferInfo);
	return screenBufferInfo.dwSize;
}

bool ConsoleController::SCREEN::setTitle(const char* str)
{
	return SetConsoleTitle(LPCSTR(str));
}

bool ConsoleController::SCREEN::hideScrollBar()
{
	coord = { rect.Right + 1,rect.Bottom + 1 };
	return SetConsoleScreenBufferSize(handle, coord);
}

bool ConsoleController::SCREEN::fullScreen()
{
	coord = { 1920,1080 };
	SetConsoleScreenBufferSize(handle, coord);
	return SetConsoleDisplayMode(handle, CONSOLE_FULLSCREEN_MODE, &coord);
}

bool ConsoleController::SCREEN::window()
{
	coord = { 0,0 };
	return SetConsoleDisplayMode(handle, CONSOLE_WINDOWED_MODE, &coord);
}

bool ConsoleController::SCREEN::setSize(short width, short height)
{
	rect.Right = rect.Left + width;
	rect.Bottom = rect.Top + height;
	coord = { width * 2, height * 2 };
	SetConsoleScreenBufferSize(handle, coord);
	return SetConsoleWindowInfo(handle, true, &rect);
}

int ConsoleController::SCREEN::getBackgroundColor()
{
	return backgroundColor;
}

bool ConsoleController::SCREEN::clean()
{
	coord = { 0,0 };
	DWORD dw;
	FillConsoleOutputAttribute(handle, WORD(backgroundColor * 16), getSize().X * getSize().Y, coord, &dw);
	return FillConsoleOutputCharacter(handle, ' ', getSize().X * getSize().Y, coord, &dw);
}

bool ConsoleController::SCREEN::setBackgroundColor(ConsoleColor color)
{
	backgroundColor = color;
	return SetConsoleTextAttribute(handle, WORD(color * 16));
}

bool ConsoleController::SCREEN::setBackgroundColor(int color)
{
	backgroundColor = color;
	return SetConsoleTextAttribute(handle, WORD(color * 16));
}

ConsoleController::SCREEN Screen;

//****************************************
//****************************************

HANDLE ConsoleController::CHARACTER::handle = *(new HANDLE);
int ConsoleController::CHARACTER::currentColor = 0;

ConsoleController::CHARACTER::CHARACTER()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

int ConsoleController::CHARACTER::getForeColor()
{
	return currentColor / 16;
}

int ConsoleController::CHARACTER::getBackColor()
{
	return currentColor % 16;
}

bool ConsoleController::CHARACTER::setForeColor(ConsoleColor color)
{
	currentColor /= 16;
	currentColor *= 16;
	currentColor += color;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::setForeColor(int color)
{
	currentColor /= 16;
	currentColor *= 16;
	currentColor += color;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::setBackColor(ConsoleColor color)
{
	currentColor %= 16;
	currentColor += int(color) * 16;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::setBackColor(int color)
{
	currentColor %= 16;
	currentColor += color * 16;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

ConsoleController::CHARACTER Character;