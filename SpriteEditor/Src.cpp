#include "../Engine/Src/Core/Sprite.h"
#include "../Engine/Src/Console.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

enum class Mode
{
	SYMBOL, COLOR
};

string ModeToString(Mode md);
void printSprite(Sprite* spr, ASCII::Console* console);
int main()
{
	Sprite* spr = nullptr;
	ASCII::Console console;
	char input;
	bool exit = false;
	CSymb symb;
	string file_path;
	Mode mode = Mode::SYMBOL;
	Vec2 curspos = Vec2(0, 2);
	Vec2 sz;
	while (!exit)
	{
		cout << "[^Z]OPEN | [^X]SAVE | [^R]" << ModeToString(mode) << " | [^F]";
		SetConsoleTextAttribute(console.getConsoleHandle(), symb.color);
		wcout << symb.symbol;
		SetConsoleTextAttribute(console.getConsoleHandle(), 7); 
		cout << " | [^Q]EXIT\n";
		SetCursorPos(0, 2);
		if(spr != NULL) printSprite(spr, &console);
		SetCursorPos(curspos.x, curspos.y);
		input = _getch();
		switch (input)
		{
		case 26: //ctrl + z
			SetCursorPos(0, 1);
			cout << "[1]OP [2]NEW";
			input = _getch();
			SetCursorPos(0, 1);
			switch (input)
			{
				case '1':
					cout << "ENTER FILE PATH: ";
					getline(cin, file_path);
					if (spr == NULL) delete spr;
					spr = new Sprite(file_path);
					SetCursorPos(curspos.x, curspos.y);
					break;
				case '2':
					cout << "ENTER SIZE: ";
					cin >> sz.x >> sz.y;
					if (spr == NULL) delete spr;
					spr = new Sprite();
					spr->setSize(sz);
					SetCursorPos(curspos.x, curspos.y);
					break;
			}
			break;
		case 24: //ctrl + x
			if (spr != NULL)
			{
				SetCursorPos(0, 1);
				cout << "ENTER FILE PATH: ";
				getline(cin, file_path);
				spr->SaveSprite(file_path);
				SetCursorPos(curspos.x, curspos.y);
			}
			break;
		case 18: //ctrl + r
			switch (mode)
			{
			case Mode::SYMBOL:
				mode = Mode::COLOR;
				break;
			case Mode::COLOR:
				mode = Mode::SYMBOL;
				break;
			}
		case 6: //ctrl + f
			if (spr != NULL)
			{
				SetCursorPos(0, 1);
				cout << "ENTER " << ModeToString(mode) << ": ";
				switch (mode)
				{
				case Mode::SYMBOL:
					wcin >> symb.symbol;
					break;
				case Mode::COLOR:
					cin >> symb.color;
					break;
				}
				SetCursorPos(curspos.x, curspos.y);
			}
			break;
		case 17: //ctrl + q
			exit = true;
			break;
		case 'w': case 'W':
			if (spr != NULL)
			{
				if (console.getCursorPosition().y > 1)
					console.MoveCursor(console.getCursorPosition() + Vec2(0, -1));
			}
			break;
		case 's': case 'S':
			if (spr != NULL)
			{
				if (console.getCursorPosition().y + 1 < spr->getSize().y + 2)
					console.MoveCursor(console.getCursorPosition() + Vec2(0, 1));
			}
			break;
		case 'a': case 'A':
			if (spr != NULL)
			{
				if (console.getCursorPosition().x > 0)
					console.MoveCursor(console.getCursorPosition() + Vec2(-1, 0));
			}
			break;
		case 'd': case 'D':
			if (spr != NULL)
			{
				if (console.getCursorPosition().x + 1 < spr->getSize().x)
					console.MoveCursor(console.getCursorPosition() + Vec2(1, 0));
			}
			break;
		case 13: //enter
			if (spr != NULL)
			{
				switch (mode)
				{
				case Mode::SYMBOL:
					spr->getSymbMatrix().at(curspos.x, curspos.y - 2).symbol = symb.symbol;
					break;
				case Mode::COLOR:
					spr->getSymbMatrix().at(curspos.x, curspos.y - 2).color = symb.color;
					break;
				}
			}
			break;
		}
		curspos = console.getCursorPosition();
		std::system("CLS");
	}
}

void printSprite(Sprite* spr, ASCII::Console* console)
{
	for (int i = 0; i < spr->getSize().x; i++)
	{
		for (int j = 0; j < spr->getSize().y; j++)
		{
			wcout << spr->getSymbMatrix().at(i, j).symbol;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spr->getSymbMatrix().at(i, j).color);
			
			console->MoveCursor(console->getCursorPosition() + Vec2(1, 0));
		}
		console->MoveCursor(console->getCursorPosition() + Vec2(0, 1));
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

string ModeToString(Mode md)
{
	switch (md)
	{
	case Mode::SYMBOL:
		return string("SYMBOL");
	case Mode::COLOR:
		return string("COLOR");
	default:
		return string("NONE");
	}
}