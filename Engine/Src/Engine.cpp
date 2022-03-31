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

//void Engine::Clear(MatrixEnum MatrixType)
//{
//	switch (MatrixType)
//	{
//	case MATRIX_MAIN:
//		for (int i = 0; i < SCREEN_HEIGHT; i++)
//			for (int j = 0; j < SCREEN_WIDTH; j++)
//				Matrix[i][j] = L' ';
//		break;
//	case MATRIX_BUFF:
//		for (int i = 0; i < SCREEN_HEIGHT; i++)
//			for (int j = 0; j < SCREEN_WIDTH; j++)
//				BuffMatrix[i][j] = L' ';
//		break;
//	}
//}

void Engine::Init()
{
	//Clear(MATRIX_MAIN);
	//Clear(MATRIX_BUFF);

	std::locale utf8_it(std::locale("It"), new std::codecvt_utf8<wchar_t>);	//Settings for correct output and input of SYMBOLS
	std::locale::global(utf8_it);
	_setmode(_fileno(stdout), _O_U16TEXT);

	console.SetWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	render.ResizeAllMatrixes(render.getScreenSize());
}

//void Engine::UpdateScreen()
//{
//	int counter = 0;
//	LPWSTR screen = new WCHAR[SCREEN_HEIGHT * SCREEN_WIDTH];
//	for (int i = 0; i < SCREEN_HEIGHT; i++)
//		for (int j = 0; j < SCREEN_WIDTH; j++)
//		{
//			Matrix[i][j] = BuffMatrix[i][j];
//			screen[counter] = Matrix[i][j];
//			counter++;
//		}
//	screen[SCREEN_HEIGHT * SCREEN_WIDTH - 1] = '\0';
//	DWORD dwBytesWritten = 0;
//	//SetWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
//	WriteConsoleOutputCharacter(console.getConsoleHandle(), screen, SCREEN_HEIGHT * SCREEN_WIDTH, {0, 0}, &dwBytesWritten);
//	delete[]screen;
//}
//
//void Engine::Draw(Vec2 location, Sprite* sprite)
//{
//	for (size_t i = 0; i < sprite->GetSize().y; i++)
//	{
//		if (i + location.y >= SCREEN_HEIGHT || location.y + i < 0) continue;
//		for (size_t j = 0; j < sprite->GetSize().x; j++)
//		{
//			if (j + location.x >= SCREEN_WIDTH || location.x + j < 0) continue;
//			BuffMatrix[i + location.y][j + location.x] = sprite->frames[0][i][j];
//		}
//	}
//}
//
//void Engine::Draw(Vec2 location, Sprite* sprite, int frame)
//{
//	if (!(frame > sprite->frames.size() - 1))
//		for (size_t i = 0; i < sprite->GetSize().y; i++)
//		{
//			if (i + location.y >= SCREEN_HEIGHT || location.y + i < 0) continue;
//			for (size_t j = 0; j < sprite->GetSize().x; j++)
//			{
//				if (j + location.x >= SCREEN_WIDTH || location.x + j < 0) continue;
//				BuffMatrix[i + location.y][j + location.x] = sprite->frames[frame][i][j];
//			}
//		}
//}
//
//void Engine::UpdateBuffMatrix()
//{
//	Clear(MATRIX_BUFF);
//	for (size_t i = 0; i < Sprite::GetAllSprites().size(); i++)
//	{
//		if (Sprite::GetAllSprites()[i]->Visible == true)
//			if (Sprite::GetAllSprites()[i]->Animate == true)
//				Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i], Sprite::GetAllSprites()[i]->NextFrame());
//			else Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i]);
//	}
//}

void Engine::OnUpdate()
{
	for (size_t i = 0; i < Object::GetAllObjects().size(); i++)
		Object::GetAllObjects()[i]->OnUpdate();
}