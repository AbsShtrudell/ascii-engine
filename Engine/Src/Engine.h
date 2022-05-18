#pragma once

#include <chrono>
#include <Console/ConsoleWIN.h>
#include <RenderSystem/Render.h>
#include <CollisionSystem/CollisionSystem.h>
#include <Game/World.h>
#include <Game/Menu/MainMenu.h>

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