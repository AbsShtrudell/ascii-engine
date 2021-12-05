#pragma once

#include <iostream>
#include <chrono>
#include <Windows.h>
#include <locale>
#include <fcntl.h>
#include <codecvt>
#include <io.h>
#include "Vector2.h"
#include "Sprite.h"
#include "Level.h"

#define SCREEN_WIDTH 85
#define SCREEN_HEIGHT 30

enum MatrixEnum { MATRIX_MAIN, MATRIX_BUFF, MATRIX_COLOR, MATRIX_BACKCOLOR };

class Engine
{

public:

	void Start();
	void Stop();
	void Init();
	void Clear(MatrixEnum MatrixType);
	void UpdateScreen();
	void UpdateBuffMatrix();
	void Draw(Vector2 location, Sprite *sprite);
	void Draw(Vector2 location, Sprite *sprite, int frame);
	void OnUpdate();

private:
	bool exit = false;
	wchar_t Matrix[SCREEN_HEIGHT][SCREEN_WIDTH], BuffMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE Console;
	CONSOLE_CURSOR_INFO CursorInfo;
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenInfo;
	HWND ConsoleWindow;
	COORD ConsoleBuffSize;
	RECT ConsoleWindowSize;
};