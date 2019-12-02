#include "ConsoleController.h"
using namespace consolr_controller;

DWORD MOUSE::_fdwMode = (
    ENABLE_WINDOW_INPUT | 
    ENABLE_MOUSE_INPUT | 
    ENABLE_EXTENDED_FLAGS
    );
HANDLE MOUSE::_handle = *(new HANDLE);
DWORD MOUSE::_numRead = *(new DWORD);
PINPUT_RECORD MOUSE::_inrc = new INPUT_RECORD[128];

MOUSE::MOUSE()
{
    _handle = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(_handle, _fdwMode);
}

COORD MOUSE::GetPosition()
{
    auto tempBool = ReadConsoleInput(_handle, _inrc, 128, &_numRead);
    return _inrc->Event.MouseEvent.dwMousePosition;
}

bool MOUSE::GetLeftDown()
{
    ReadConsoleInput(_handle, _inrc, 128, &_numRead);
    return _inrc->Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
}

bool MOUSE::GetRightDown()
{
    ReadConsoleInput(_handle, _inrc, 128, &_numRead);
    return _inrc->Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED;
}

bool MOUSE::GetBothDown()
{
    ReadConsoleInput(_handle, _inrc, 128, &_numRead);
    return _inrc->Event.MouseEvent.dwButtonState == (
        FROM_LEFT_1ST_BUTTON_PRESSED +
        RIGHTMOST_BUTTON_PRESSED
        );
}

MOUSE Mouse;

//****************************************
//****************************************

HANDLE CURSOR::_handle = *(new HANDLE);
CONSOLE_CURSOR_INFO CURSOR::_CursorInfo = *(
    new CONSOLE_CURSOR_INFO
    );
COORD CURSOR::_coord = *(new COORD);

CURSOR::CURSOR()
{
    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(_handle, &_CursorInfo);
}

bool CURSOR::Hide()
{
    _CursorInfo.bVisible = false;
    return SetConsoleCursorInfo(_handle, &_CursorInfo);
}

bool CURSOR::Show()
{
    _CursorInfo.bVisible = true;
    return SetConsoleCursorInfo(_handle, &_CursorInfo);
}

bool CURSOR::SetPosition(short x, short y)
{
    _coord = { x,y };
    return SetConsoleCursorPosition(_handle, _coord);
}

bool CURSOR::SetPosition(COORD pos)
{
    _coord = pos;
    return SetConsoleCursorPosition(_handle, _coord);
}

CURSOR Cursor;

//****************************************
//****************************************

HANDLE SCREEN::_handle = *(new HANDLE);
CONSOLE_SCREEN_BUFFER_INFO SCREEN::_screenBufferInfo = *(
    new CONSOLE_SCREEN_BUFFER_INFO
    );
SMALL_RECT SCREEN::_rect = *(new SMALL_RECT);
COORD SCREEN::_coord = *(new COORD);
int SCREEN::_backgroundColor = 
    (int)ConsoleColor::Black;

SCREEN::SCREEN()
{
    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(_handle, &_screenBufferInfo);
    _rect = _screenBufferInfo.srWindow;
}

COORD SCREEN::GetSize()
{
    GetConsoleScreenBufferInfo(_handle, &_screenBufferInfo);
    return _screenBufferInfo.dwSize;
}

bool SCREEN::SetTitle(const char* str)
{
    return SetConsoleTitle(LPCSTR(str));
}

bool SCREEN::HideScrollBar()
{
    _coord = { _rect.Right + 1,_rect.Bottom + 1 };
    return SetConsoleScreenBufferSize(_handle, _coord);
}

bool SCREEN::FullScreen()
{
    _coord = { 1920,1080 };
    SetConsoleScreenBufferSize(_handle, _coord);
    return SetConsoleDisplayMode(_handle, CONSOLE_FULLSCREEN_MODE, &_coord);
}

bool SCREEN::Window()
{
    _coord = { 0,0 };
    return SetConsoleDisplayMode(_handle, CONSOLE_WINDOWED_MODE, &_coord);
}

bool SCREEN::SetSize(short width, short height)
{
    _rect.Right = _rect.Left + width;
    _rect.Bottom = _rect.Top + height;
    _coord = { width * 2, height * 2 };
    SetConsoleScreenBufferSize(_handle, _coord);
    return SetConsoleWindowInfo(_handle, true, &_rect);
}

int SCREEN::GetBackgroundColor()
{
    return _backgroundColor;
}

bool SCREEN::Clean()
{
    _coord = { 0,0 };
    DWORD dw;
    FillConsoleOutputAttribute(
        _handle,
        WORD(_backgroundColor * 16),
        GetSize().X * GetSize().Y,
        _coord, &dw
    );
    return FillConsoleOutputCharacter(
        _handle,
        ' ',
        GetSize().X * GetSize().Y,
        _coord,
        &dw
    );
}

bool SCREEN::SetBackgroundColor(ConsoleColor color)
{
    _backgroundColor = (int)color;
    return SetConsoleTextAttribute(_handle, WORD((int)color * 16));
}

bool SCREEN::SetBackgroundColor(int color)
{
    _backgroundColor = color;
    return SetConsoleTextAttribute(_handle, WORD(color * 16));
}

SCREEN Screen;

//****************************************
//****************************************

HANDLE CHARACTER::_handle = *(new HANDLE);
int CHARACTER::_currentColor = 0;

CHARACTER::CHARACTER()
{
    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

int CHARACTER::GetForeColor()
{
    return _currentColor / 16;
}

int CHARACTER::GetBackColor()
{
    return _currentColor % 16;
}

bool CHARACTER::SetForeColor(ConsoleColor color)
{
    _currentColor /= 16;
    _currentColor *= 16;
    _currentColor += (int)color;
    return SetConsoleTextAttribute(_handle, WORD(_currentColor));
}

bool CHARACTER::SetForeColor(int color)
{
    _currentColor /= 16;
    _currentColor *= 16;
    _currentColor += color;
    return SetConsoleTextAttribute(_handle, WORD(_currentColor));
}

bool CHARACTER::SetBackColor(ConsoleColor color)
{
    _currentColor %= 16;
    _currentColor += int(color) * 16;
    return SetConsoleTextAttribute(_handle, WORD(_currentColor));
}

bool CHARACTER::SetBackColor(int color)
{
    _currentColor %= 16;
    _currentColor += color * 16;
    return SetConsoleTextAttribute(_handle, WORD(_currentColor));
}

CHARACTER Character;