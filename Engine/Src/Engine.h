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

#define SCREEN_WIDTH 85
#define SCREEN_HEIGHT 30

class Engine
{

public:

	void Start();
	void Stop();
	void Init();
	void OnUpdate();

private:
	ASCII::Console console;
	Render render;
	bool exit = false;
};