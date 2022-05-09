#pragma once
#include <Console/IConsole.h>

namespace ASCII
{
	class ConsoleWIN : public IConsole
	{
	public:

		ConsoleWIN();
		~ConsoleWIN();

		virtual void HideCursor() override;
		virtual void MoveCursor(Vec2 position) override;
		virtual void SetWindow(int Width, int Height) override;
		virtual void WriteConsoleSymbols(wchar_t* symbols, int symbolsAmount) override;
		virtual void WriteConsoleAttribute(int* colors, int colorsAmount) override;

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
