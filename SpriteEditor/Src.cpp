#include "../Engine/Src/Core/Sprite.h"
#include "../Engine/Src/Console.h"
#include <iostream>
#include <conio.h>

using namespace std;

enum class Mode
{
	SYMBOL, FOREGR, BACKGR
};

int main()
{
	Sprite* spr = nullptr;

	char input;
	bool exit = false;

	string file_path;
	Mode mode = Mode::SYMBOL;
	while (exit)
	{
		cout << "[^Z]OPEN | [^X]SAVE | [^R]" << " | [^F] | [^Q]EXIT\n\n";

		switch (input)
		{
		case 'z':
			
			break;
		case 'x':
			
			break;
		case 'R':
			switch (mode)
			{
			case Mode::SYMBOL:
				mode = Mode::FOREGR;
				break;
			case Mode::FOREGR:
				mode = Mode::BACKGR;
				break;
			case Mode::BACKGR:
				mode = Mode::SYMBOL;
				break;
			}
		case 'q':
			exit = true;
			break;
		}
	}
}

void printSprite(Sprite* spr)
{
	for (int i = 0; i < spr->getSize().x; i++)
	{
		for (int j = 0; j < spr->getSize().y; j++)
		{
			cout << spr->getSymbMatrix().at(i, j).symbol;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spr->getSymbMatrix().at(i, j).color);
		}
	}
}