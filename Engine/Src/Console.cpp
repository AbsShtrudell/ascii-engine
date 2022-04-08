#include "Console.h"

ASCII::Console::Console()
{
	ConsoleHWND = GetConsoleWindow();
	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

ASCII::Console::~Console()
{
}

void ASCII::Console::HideCursor()
{
	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle,&CursorInfo);
}

void ASCII::Console::HideScrollBar()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
	COORD new_screen_buffer_size;
	new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
		screenBufferInfo.srWindow.Left + 1; // Columns
	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
		screenBufferInfo.srWindow.Top + 1; // Rows
	SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
}

void ASCII::Console::MoveCursor(Vec2 position)
{
	COORD pos;
	pos.X = position.x;
	pos.Y = position.y;

	SetConsoleCursorPosition(getConsoleHandle(), pos);
}

void ASCII::Console::SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width - 1;
	coord.Y = Height - 1;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
	HideScrollBar();
}

void ASCII::Console::WriteConsoleSymbols(wchar_t* symbols,int symbolsAmount)
{
	DWORD dword = NULL;
	WriteConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), symbols, symbolsAmount, { 0, 0 }, &dword);
	return;
}

const HANDLE ASCII::Console::getConsoleHandle() const
{
	return ConsoleHandle;
}

const HWND ASCII::Console::getConsoleHWND() const
{
	return ConsoleHWND;
}

const CONSOLE_CURSOR_INFO ASCII::Console::getCursorInfo() 
{
	GetConsoleCursorInfo(ConsoleHandle, &CursorInfo);
	return CursorInfo;
}

const CONSOLE_SCREEN_BUFFER_INFO ASCII::Console::getConsoleScreenBuffInfo() 
{
	GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleScreenBuffInfo);
	return ConsoleScreenBuffInfo;
}

const COORD ASCII::Console::getConsoleBuffSize() 
{
	ConsoleBuffSize = getConsoleScreenBuffInfo().dwSize;
	return ConsoleBuffSize;
}

const WINDOWINFO ASCII::Console::getConsoleWindowInfo() 
{
	GetWindowInfo(ConsoleHWND, &ConsoleWindowInfo);
	return ConsoleWindowInfo;
}

const RECT ASCII::Console::getConsoleWindowSize() 
{
	ConsoleWindowSize = getConsoleWindowInfo().rcWindow; //??
	return ConsoleWindowSize;
}

const Vec2 ASCII::Console::getCursorPosition()
{
	return Vec2(getConsoleScreenBuffInfo().dwCursorPosition.X, getConsoleScreenBuffInfo().dwCursorPosition.Y);
}


