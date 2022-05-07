#pragma once
#include <Windows.h>
#include <Math/Vec2.h>

namespace ASCII
{
	class Console
	{
	public:

		ASCII::Console();
		ASCII::Console(Console& console);
		~Console();

		void HideCursor();
		void HideScrollBar();
		void MoveCursor(Vec2 position);
		void SetWindow(int Width, int Height);
		void WriteConsoleSymbols(wchar_t* symbols, int symbolsAmount);
		void WriteConsoleAttribute(WORD* colors, int colorsAmount);

		const HANDLE getConsoleHandle() const;
		const HWND getConsoleHWND() const;
		const CONSOLE_CURSOR_INFO getCursorInfo();
		const CONSOLE_SCREEN_BUFFER_INFO getConsoleScreenBuffInfo();
		const COORD getConsoleBuffSize();
		const WINDOWINFO getConsoleWindowInfo();
		const RECT getConsoleWindowSize();	
		const Vec2 getCursorPosition();

	private:
		HANDLE ConsoleHandle;
		HWND ConsoleHWND;

		CONSOLE_CURSOR_INFO CursorInfo;
		CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBuffInfo;
		RECT ConsoleWindowSize;
		COORD ConsoleBuffSize;
		WINDOWINFO ConsoleWindowInfo;
	};
}
