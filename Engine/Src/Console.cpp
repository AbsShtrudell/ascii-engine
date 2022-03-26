#include "Console.h"

ASCII::Console::Console()
{
	ConsoleWindow = GetConsoleWindow();
}

void ASCII::Console::SetFullscreen()
{
	ShowWindow(ConsoleWindow, SW_MAXIMIZE);
}
