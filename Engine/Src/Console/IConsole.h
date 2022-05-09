#pragma once
#include <Windows.h>
#include <stdexcept>
#include <Math/Vec2.h>

namespace ASCII
{
	class IConsole
	{
	public:
		IConsole();
		virtual ~IConsole();

		virtual void HideCursor() = 0;
		virtual void MoveCursor(Vec2 position) = 0;
		virtual void SetWindow(int Width, int Height) = 0;
		virtual void WriteConsoleSymbols(wchar_t* symbols, int symbolsAmount) = 0;
		virtual void WriteConsoleAttribute(int* colors, int colorsAmount) = 0;
	};
}

