#include "Engine.h"

void Engine::Start()
{
	MainMenu* world = new MainMenu();

	while (!exit)
	{
		InputSystem::Get()->Update();
		CollisionSystem::get()->Update();
		Update();
		render.UpdateBuffMatrix();
		render.UpdateScreen();
		DestroyObjects();
		Sleep(8);
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
