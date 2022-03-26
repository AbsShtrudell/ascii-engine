#pragma once
#include <Windows.h>
#include "Core/Vec2.h"

namespace ASCII
{
	class Console
	{
	public:

		ASCII::Console();
		~Console();

		void SetConsoleWindowSize();
		void SetConsoleBifferSize(Vec2 size);
		void SetFullscreen();


	private:
		HANDLE HConsole;
		CONSOLE_CURSOR_INFO CursorInfo;
		CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenInfo;
		HWND ConsoleWindow;
		COORD ConsoleBuffSize;
		RECT ConsoleWindowSize;
	};
}
