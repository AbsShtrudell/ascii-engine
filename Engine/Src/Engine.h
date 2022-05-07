#pragma once

#include <chrono>
#include <Console/Console.h>
#include <RenderSystem/Render.h>
#include <CollisionSystem/CollisionSystem.h>
#include "Game/Player.h"
#include "Game/Box.h"

#define SCREEN_WIDTH 85
#define SCREEN_HEIGHT 30

class Engine
{

public:
	void Start();
	void Stop();
	void Init();
	void Update();

private:
	ASCII::Console console;
	Render render;
	bool exit = false;
};