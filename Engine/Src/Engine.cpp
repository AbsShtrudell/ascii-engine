#include "Engine.h"

void Engine::Start()
{
	Sprite z(32, 20, "E:\\Projects\\VS Projects\\ALife\\WD_Quad.txt");
	Sprite j(15, 9, "E:\\Projects\\VS Projects\\ALife\\test.txt");
	j.LoadFrame("E:\\Projects\\VS Projects\\ALife\\test1.txt", 1);
	j.LoadFrame("E:\\Projects\\VS Projects\\ALife\\test2.txt", 2);
	j.SetLocation(Vec2(1, 1));

	Object g;
	int c = Object::GetAllObjectsOfClass<Sprite>().size();
	int i = Object::GetAllObjects().size();
	Vec2 l;

	while (!exit)
	{
		InputSystem::Get()->Update();
		UpdateBuffMatrix();
		UpdateScreen();
		Sleep(40);
	}
}
void Engine::Stop()
{
	exit = true;
}

void Engine::Clear(MatrixEnum MatrixType)
{
	switch (MatrixType)
	{
	case MATRIX_MAIN:
		for (int i = 0; i < SCREEN_HEIGHT; i++)
			for (int j = 0; j < SCREEN_WIDTH; j++)
				Matrix[i][j] = L' ';
		break;
	case MATRIX_BUFF:
		for (int i = 0; i < SCREEN_HEIGHT; i++)
			for (int j = 0; j < SCREEN_WIDTH; j++)
				BuffMatrix[i][j] = L' ';
		break;
	}
}

void Engine::Init()
{
	Clear(MATRIX_MAIN);
	Clear(MATRIX_BUFF);


	std::locale utf8_it(std::locale("It"), new std::codecvt_utf8<wchar_t>);	//Settings for correct output and input of SYMBOLS
	std::locale::global(utf8_it);
	_setmode(_fileno(stdout), _O_U16TEXT);


	ConsoleWindow = GetConsoleWindow();
	GetWindowRect(ConsoleWindow, &ConsoleWindowSize); //stores the console's current dimensions
	//MoveWindow(ConsoleWindow, ConsoleWindowSize.left, ConsoleWindowSize.top, 800, 510, TRUE); // 800 width, 100 height
	//SetWindowLong(ConsoleWindow, GWL_STYLE, GetWindowLong(ConsoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);


	Console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Console, &ConsoleScreenInfo);
	ConsoleBuffSize =
	{
		SCREEN_HEIGHT - 10,SCREEN_WIDTH - 10
		/*SHORT(ConsoleScreenInfo.srWindow.Right - ConsoleScreenInfo.srWindow.Left),
		SHORT(ConsoleScreenInfo.srWindow.Bottom - ConsoleScreenInfo.srWindow.Top) 	*/
	};
	SetConsoleScreenBufferSize(Console, ConsoleBuffSize);
	_SMALL_RECT  Rect;
	Rect.Right = SCREEN_WIDTH - 1;
	Rect.Left = 0;
	Rect.Top = 0;
	Rect.Bottom = SCREEN_HEIGHT - 1;
	SetConsoleWindowInfo(Console, TRUE, &Rect);

	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;
	SetConsoleCursorInfo(Console, &CursorInfo);
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void Engine::UpdateScreen()
{
	int counter = 0;
	LPWSTR screen = new WCHAR[SCREEN_HEIGHT * SCREEN_WIDTH];
	for (int i = 0; i < SCREEN_HEIGHT; i++)
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			Matrix[i][j] = BuffMatrix[i][j];
			screen[counter] = Matrix[i][j];
			counter++;
		}
	screen[SCREEN_HEIGHT * SCREEN_WIDTH - 1] = '\0';
	DWORD dwBytesWritten = 0;
	WriteConsoleOutputCharacter(Console, screen, SCREEN_HEIGHT * SCREEN_WIDTH, { 0, 0 }, &dwBytesWritten);
}

void Engine::Draw(Vec2 location, Sprite* sprite)
{
	for (size_t i = 0; i < sprite->GetSize().y; i++)
	{
		if (i + location.y >= SCREEN_HEIGHT || location.y + i < 0) continue;
		for (size_t j = 0; j < sprite->GetSize().x; j++)
		{
			if (j + location.x >= SCREEN_WIDTH || location.x + j < 0) continue;
			BuffMatrix[i + location.y][j + location.x] = sprite->frames[0][i][j];
		}
	}
}

void Engine::Draw(Vec2 location, Sprite* sprite, int frame)
{
	if (!(frame > sprite->frames.size() - 1))
		for (size_t i = 0; i < sprite->GetSize().y; i++)
		{
			if (i + location.y >= SCREEN_HEIGHT || location.y + i < 0) continue;
			for (size_t j = 0; j < sprite->GetSize().x; j++)
			{
				if (j + location.x >= SCREEN_WIDTH || location.x + j < 0) continue;
				BuffMatrix[i + location.y][j + location.x] = sprite->frames[frame][i][j];
			}
		}
}

void Engine::UpdateBuffMatrix()
{
	Clear(MATRIX_BUFF);
	for (size_t i = 0; i < Sprite::GetAllSprites().size(); i++)
	{
		if (Sprite::GetAllSprites()[i]->Visible == true)
			if (Sprite::GetAllSprites()[i]->Animate == true)
				Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i], Sprite::GetAllSprites()[i]->NextFrame());
			else Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i]);
	}
}

void OnUpdate()
{
	for (size_t i = 0; i < Object::GetAllObjects().size(); i++)
		Object::GetAllObjects()[i]->OnUpdate();
}