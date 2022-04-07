#include "Engine.h"

void Engine::Start()
{
	Sprite f;
	f.LoadSprite("F:\\Projects\\VS Projects\\ASCIIEngine\\Resources\\WD_Quad.spr");
	while (!exit)
	{
		InputSystem::Get()->Update();
		render.UpdateBuffMatrix();
		render.UpdateScreen();
		Sleep(40);
	}
}

void Engine::Stop()
{
	exit = true;
}

void Engine::Init()
{
	std::locale utf8_it(std::locale("It"), new std::codecvt_utf8<wchar_t>);	//Settings for correct output and input of SYMBOLS
	std::locale::global(utf8_it);
	_setmode(_fileno(stdout), _O_U16TEXT);

	console.HideCursor();
	console.SetWindow(render.getScreenSize().x, render.getScreenSize().y);
	render.ResizeAllMatrixes(render.getScreenSize());
}

void Engine::Update()
{
	for (size_t i = 0; i < Object::GetAllObjects().size(); i++)
		Object::GetAllObjects()[i]->OnUpdate();
}