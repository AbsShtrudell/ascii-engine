#include "Engine.h"

void Engine::Start()
{
	Sprite z(32, 20, "..\\Resources\\WD_Quad.txt");
	Sprite j(15, 9, "..\\Resources\\test.txt");
	j.LoadFrame("..\\Resources\\test1.txt", 1);
	j.LoadFrame("..\\Resources\\test2.txt", 2);
	j.SetLocation(Vec2(1, 1));

	Object g;
	int c = Object::GetAllObjectsOfClass<Sprite>().size();
	int i = Object::GetAllObjects().size();
	Vec2 l;

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

void Engine::OnUpdate()
{
	for (size_t i = 0; i < Object::GetAllObjects().size(); i++)
		Object::GetAllObjects()[i]->OnUpdate();
}