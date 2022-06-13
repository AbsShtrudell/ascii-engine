#include "Engine.h"
#include <chrono>

void Engine::Start()
{
	World* world = new World();

	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;

	double duration;
	while (!exit)
	{
		start = std::chrono::system_clock::now();
		InputSystem::Get()->Update();
		CollisionSystem::get()->Update();
		Update();
		render.UpdateBuffMatrix();
		render.UpdateScreen();
		DestroyObjects();
		end = std::chrono::system_clock::now();
		duration = 1000 / 60 - std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		Sleep(duration > 0? duration: 0);
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

void Engine::DestroyObjects()
{
	Object* temp = nullptr;

	while(Object::getDestroyedObjects().size() > 0)
	{
		temp = Object::getDestroyedObjects().at(Object::getDestroyedObjects().size() - 1);
		Object::getDestroyedObjects().pop_back();
		delete temp;
	}
}
