#include "Engine.h"

void Engine::Start()
{
	World* world = new World();

	while (!exit)
	{
		InputSystem::Get()->Update();
		CollisionSystem::get()->Update();
		Update();
		render.UpdateBuffMatrix();
		render.UpdateScreen();
		Sleep(10);
	}
}

void Engine::Stop()
{
	exit = true;
}

void Engine::Init()
{
	console.HideCursor();
	console.SetWindow(render.getScreenSize().x, render.getScreenSize().y);
	render.ResizeScreen(render.getScreenSize());
}

void Engine::Update()
{
	for (size_t i = 0; i < Object::getAllObjects().size(); i++)
		Object::getAllObjects()[i]->OnUpdate();
}