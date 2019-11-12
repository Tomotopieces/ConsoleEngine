#include "ConsoleController.h"

HANDLE ConsoleController::MOUSE::handle = *(new HANDLE);
DWORD ConsoleController::MOUSE::numRead = *(new DWORD);
INPUT_RECORD ConsoleController::MOUSE::inrc = *(new INPUT_RECORD);

ConsoleController::MOUSE::MOUSE()
{
	handle = GetStdHandle(STD_INPUT_HANDLE);
}

COORD ConsoleController::MOUSE::GetPosition()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwMousePosition;
}

bool ConsoleController::MOUSE::GetLeftDown()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
}

bool ConsoleController::MOUSE::GetRightDown()
{
	ReadConsoleInput(handle, &inrc, 1, &numRead);
	return inrc.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED;
}

bool ConsoleController::MOUSE::GetBothDown()
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

bool ConsoleController::CURSOR::Hide()
{
	CursorInfo.bVisible = false;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool ConsoleController::CURSOR::Show()
{
	CursorInfo.bVisible = true;
	return SetConsoleCursorInfo(handle, &CursorInfo);
}

bool ConsoleController::CURSOR::SetPosition(short x, short y)
{
	coord = { x,y };
	return SetConsoleCursorPosition(handle, coord);
}

bool ConsoleController::CURSOR::SetPosition(COORD pos)
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

const COORD ConsoleController::SCREEN::GetSize()
{
	GetConsoleScreenBufferInfo(handle, &screenBufferInfo);
	return screenBufferInfo.dwSize;
}

bool ConsoleController::SCREEN::SetTitle(const char* str)
{
	return SetConsoleTitle(LPCSTR(str));
}

bool ConsoleController::SCREEN::HideScrollBar()
{
	coord = { rect.Right + 1,rect.Bottom + 1 };
	return SetConsoleScreenBufferSize(handle, coord);
}

bool ConsoleController::SCREEN::FullScreen()
{
	coord = { 1920,1080 };
	SetConsoleScreenBufferSize(handle, coord);
	return SetConsoleDisplayMode(handle, CONSOLE_FULLSCREEN_MODE, &coord);
}

bool ConsoleController::SCREEN::Window()
{
	coord = { 0,0 };
	return SetConsoleDisplayMode(handle, CONSOLE_WINDOWED_MODE, &coord);
}

bool ConsoleController::SCREEN::SetSize(short width, short height)
{
	rect.Right = rect.Left + width;
	rect.Bottom = rect.Top + height;
	coord = { width * 2, height * 2 };
	SetConsoleScreenBufferSize(handle, coord);
	return SetConsoleWindowInfo(handle, true, &rect);
}

int ConsoleController::SCREEN::GetBackgroundColor()
{
	return backgroundColor;
}

bool ConsoleController::SCREEN::Clean()
{
	coord = { 0,0 };
	DWORD dw;
	FillConsoleOutputAttribute(handle, WORD(backgroundColor * 16), GetSize().X * GetSize().Y, coord, &dw);
	return FillConsoleOutputCharacter(handle, ' ', GetSize().X * GetSize().Y, coord, &dw);
}

bool ConsoleController::SCREEN::SetBackgroundColor(ConsoleColor color)
{
	backgroundColor = color;
	return SetConsoleTextAttribute(handle, WORD(color * 16));
}

bool ConsoleController::SCREEN::SetBackgroundColor(int color)
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

int ConsoleController::CHARACTER::GetForeColor()
{
	return currentColor / 16;
}

int ConsoleController::CHARACTER::GetBackColor()
{
	return currentColor % 16;
}

bool ConsoleController::CHARACTER::SetForeColor(ConsoleColor color)
{
	currentColor /= 16;
	currentColor *= 16;
	currentColor += color;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::SetForeColor(int color)
{
	currentColor /= 16;
	currentColor *= 16;
	currentColor += color;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::SetBackColor(ConsoleColor color)
{
	currentColor %= 16;
	currentColor += int(color) * 16;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

bool ConsoleController::CHARACTER::SetBackColor(int color)
{
	currentColor %= 16;
	currentColor += color * 16;
	return SetConsoleTextAttribute(handle, WORD(currentColor));
}

ConsoleController::CHARACTER Character;