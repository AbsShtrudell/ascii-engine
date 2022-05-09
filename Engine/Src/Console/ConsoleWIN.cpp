#include "ConsoleWIN.h"

ASCII::ConsoleWIN::ConsoleWIN()
{
	ConsoleHWND = GetConsoleWindow();
	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

ASCII::ConsoleWIN::~ConsoleWIN()
{
}

void ASCII::ConsoleWIN::HideCursor()
{
	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle,&CursorInfo);
}

void ASCII::ConsoleWIN::MoveCursor(Vec2 position)
{
	COORD pos;
	pos.X = position.x;
	pos.Y = position.y;

	SetConsoleCursorPosition(getConsoleHandle(), pos);
}

void ASCII::ConsoleWIN::SetWindow(int Width, int Height)
{
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (Handle == INVALID_HANDLE_VALUE)
        throw std::runtime_error("Unable to get stdout handle.");

    {
        COORD largestSize = GetLargestConsoleWindowSize(Handle);
        if (Width > largestSize.X)
            throw std::invalid_argument("The x dimension is too large.");
        if (Height > largestSize.Y)
            throw std::invalid_argument("The y dimension is too large.");
    }

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if (!GetConsoleScreenBufferInfo(Handle, &bufferInfo))
        throw std::runtime_error("Unable to retrieve screen buffer info.");

    SMALL_RECT& winInfo = bufferInfo.srWindow;
    COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

    if (windowSize.X > Width || windowSize.Y > Height)
    {
        // window size needs to be adjusted before the buffer size can be reduced.
        SMALL_RECT info =
        {
            0,
            0,
            Width < windowSize.X ? Width - 1 : windowSize.X - 1,
            Height < windowSize.Y ? Height - 1 : windowSize.Y - 1
        };

        if (!SetConsoleWindowInfo(Handle, TRUE, &info))
            throw std::runtime_error("Unable to resize window before resizing buffer.");
    }

    COORD size = { Width, Height };
    if (!SetConsoleScreenBufferSize(Handle, size))
        throw std::runtime_error("Unable to resize screen buffer.");


    SMALL_RECT info = { 0, 0, Width - 1, Height - 1 };
    if (!SetConsoleWindowInfo(Handle, TRUE, &info))
        throw std::runtime_error("Unable to resize window after resizing buffer.");
}

void ASCII::ConsoleWIN::WriteConsoleSymbols(wchar_t* symbols,int symbolsAmount)
{
	DWORD dword = NULL;
	WriteConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), symbols, symbolsAmount, { 0, 0 }, &dword);
}

void ASCII::ConsoleWIN::WriteConsoleAttribute(int* colors, int colorsAmount)
{
	DWORD dword = NULL;

    WORD* screenColor = new WORD[colorsAmount];
    for (int i = 0; i < colorsAmount; i++)
        screenColor[i] = colors[i];

	WriteConsoleOutputAttribute(getConsoleHandle(), screenColor, colorsAmount, { 0,0 }, &dword);

    delete[]screenColor;
}

const HANDLE ASCII::ConsoleWIN::getConsoleHandle() const
{
	return ConsoleHandle;
}

const HWND ASCII::ConsoleWIN::getConsoleHWND() const
{
	return ConsoleHWND;
}

const CONSOLE_CURSOR_INFO ASCII::ConsoleWIN::getCursorInfo()
{
	GetConsoleCursorInfo(ConsoleHandle, &CursorInfo);
	return CursorInfo;
}

const CONSOLE_SCREEN_BUFFER_INFO ASCII::ConsoleWIN::getConsoleScreenBuffInfo()
{
	GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleScreenBuffInfo);
	return ConsoleScreenBuffInfo;
}

const COORD ASCII::ConsoleWIN::getConsoleBuffSize()
{
	ConsoleBuffSize = getConsoleScreenBuffInfo().dwSize;
	return ConsoleBuffSize;
}

const WINDOWINFO ASCII::ConsoleWIN::getConsoleWindowInfo()
{
	GetWindowInfo(ConsoleHWND, &ConsoleWindowInfo);
	return ConsoleWindowInfo;
}

const RECT ASCII::ConsoleWIN::getConsoleWindowSize()
{
	ConsoleWindowSize = getConsoleWindowInfo().rcWindow; //??
	return ConsoleWindowSize;
}

const Vec2 ASCII::ConsoleWIN::getCursorPosition()
{
	return Vec2(getConsoleScreenBuffInfo().dwCursorPosition.X, getConsoleScreenBuffInfo().dwCursorPosition.Y);
}


