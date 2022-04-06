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
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height;
	Rect.Right = Width+1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
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


