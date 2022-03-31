#pragma once

#include <iostream>
#include <chrono>
#include <locale>
#include <fcntl.h>
#include <codecvt>
#include <io.h>
#include <Windows.h>
#include "Render.h"
#include "Core/Sprite.h"
#include "Core/Vec2.h"
//#include "Console.h"

#define SCREEN_WIDTH 85
#define SCREEN_HEIGHT 30

//enum MatrixEnum { MATRIX_MAIN, MATRIX_BUFF, MATRIX_COLOR, MATRIX_BACKCOLOR };

class Engine
{

public:

	void Start();
	void Stop();
	void Init();
	//void Clear(MatrixEnum MatrixType);
	//void UpdateScreen();
	//void UpdateBuffMatrix();
	//void Draw(Vec2 location, Sprite *sprite);
	//void Draw(Vec2 location, Sprite *sprite, int frame);
	void OnUpdate();
	//void SetWindow(int Width, int Height);

private:
	ASCII::Console console;
	Render render;
	bool exit = false;
	wchar_t Matrix[SCREEN_HEIGHT][SCREEN_WIDTH], BuffMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];
};