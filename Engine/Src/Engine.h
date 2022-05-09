#pragma once

#include <chrono>
#include <Console/ConsoleWIN.h>
#include <RenderSystem/Render.h>
#include <CollisionSystem/CollisionSystem.h>
#include <Game/World.h>

#define SCREEN_WIDTH 85
#define SCREEN_HEIGHT 30

class Engine
{

public:
	void Start();
	void Stop();
	void Init();
	void Update();
	void DestroyObjects();

private:
	ASCII::ConsoleWIN console;
	Render render;
	bool exit = false;
};