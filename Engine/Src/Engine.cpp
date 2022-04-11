#include "Engine.h"

void Engine::Start()
{
	Player player;
	Box f1;
	render.setCamera(player.getCamera());
	f1.setLocation(Vec2(0, 24));

	while (!exit)
	{
		InputSystem::Get()->Update();
		CollisionSystem::get()->Update();
		render.UpdateBuffMatrix();
		render.UpdateScreen();
		Sleep(30);
	}
}

void Engine::Stop()
{
	exit = true;
}

void Engine::Init()
{
	//std::locale utf8_it(std::locale("It"), new std::codecvt_utf8<wchar_t>);	//Settings for correct output and input of SYMBOLS
	//std::locale::global(utf8_it);
	//_setmode(_fileno(stdout), _O_U16TEXT);

	console.HideCursor();
	console.SetWindow(render.getScreenSize().x, render.getScreenSize().y);
	render.ResizeAllMatrixes(render.getScreenSize());
}

void Engine::Update()
{
	for (size_t i = 0; i < Object::getAllObjects().size(); i++)
		Object::getAllObjects()[i]->OnUpdate();
}