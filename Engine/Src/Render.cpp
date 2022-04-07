#include "Render.h"

Render::Render()
{
	SymbolMatrix = new Matrix<wchar_t>(screenSize, L' ');
	BuffSymbolMatrix = new Matrix<wchar_t>(screenSize, L' ');
	ColorMatrix = new Matrix<int>(screenSize, 0);
	BuffColorMatrix = new Matrix<int>(screenSize, 0);
	BackColorMatrix = new Matrix<int>(screenSize, 0);
	BuffBackColorMatrix = new Matrix<int>(screenSize, 0);
}

Render::~Render()
{
}

void Render::Clear(MatrixEnum MatrixType)
{
	switch (MatrixType)
	{
	case MatrixEnum::SYMBOL_MATRIX:
		SymbolMatrix->Clear();
		break;
	case MatrixEnum::SYMBOL_MATRIX_BUFF:
		BuffSymbolMatrix->Clear();
		break;
	case MatrixEnum::COLOR_MATRIX:
		ColorMatrix->Clear();
		break;
	case MatrixEnum::COLOR_MATRIX_BUFF:
		BuffColorMatrix->Clear();
		break;
	case MatrixEnum::BACKCOLOR_MATRIX:
		BackColorMatrix->Clear();
		break;
	case MatrixEnum::BACKCOLOR_MATRIX_BUFF:
		BuffBackColorMatrix->Clear();
		break;
	}
}

void Render::ResizeAllMatrixes(Vec2 size)
{
	SymbolMatrix->setSize(size);
	BuffSymbolMatrix->setSize(size);
	ColorMatrix->setSize(size);
	BuffColorMatrix->setSize(size);
	BackColorMatrix->setSize(size);
	BuffBackColorMatrix->setSize(size);
	screenSize = size;
}

void Render::ResizeMatrix(MatrixEnum MatrixType, Vec2 size)
{
	switch (MatrixType)
	{
	case MatrixEnum::SYMBOL_MATRIX:
		SymbolMatrix->setSize(size);
		break;
	case MatrixEnum::SYMBOL_MATRIX_BUFF:
		BuffSymbolMatrix->setSize(size);
		break;
	case MatrixEnum::COLOR_MATRIX:
		ColorMatrix->setSize(size);
		break;
	case MatrixEnum::COLOR_MATRIX_BUFF:
		BuffColorMatrix->setSize(size);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX:
		BackColorMatrix->setSize(size);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX_BUFF:
		BuffBackColorMatrix->setSize(size);
		break;
	}
	screenSize = size;
}

void Render::UpdateScreen()
{
	int counter = 0;
	LPWSTR screen = new WCHAR[screenSize.y * screenSize.x];
	for (int i = 0; i < screenSize.x; i++)
		for (int j = 0; j < screenSize.y; j++)
		{
			SymbolMatrix->at(i, j) = BuffSymbolMatrix->at(i, j);
			screen[counter] = SymbolMatrix->at(i, j);
			counter++;
		}
	DWORD dwBytesWritten = 0;

	console.WriteConsoleSymbols(screen, screenSize.y * screenSize.x);
	Clear(MatrixEnum::SYMBOL_MATRIX_BUFF);
	delete[]screen;
}

void Render::Draw(Vec2 location, IDrawObj* drawObj)
{
	for (size_t i = 0; i < drawObj->getSize().x; i++)
	{
		if (i + location.x >= screenSize.x || location.x + i < 0) continue;
		for (size_t j = 0; j < drawObj->getSize().y; j++)
		{
			if (j + location.y >= screenSize.y || location.y + j < 0) continue;
			BuffSymbolMatrix->at(i + location.x,j + location.y) = drawObj->getTexture()->at(i, j).symbol;
		}
	}
}

const Vec2 Render::getScreenSize() const
{
	return screenSize;
}

void Render::UpdateBuffMatrix()
{
	Clear(MatrixEnum::SYMBOL_MATRIX);
	for (size_t i = 0; i < IDrawObj::getAllDrawObjects().size(); i++)
	{
		if (IDrawObj::getAllDrawObjects()[i]->isVisible() == true)
		{
			Draw(IDrawObj::getAllDrawObjects()[i]->getDrawLoacation(), IDrawObj::getAllDrawObjects()[i]);
			IDrawObj::getAllDrawObjects()[i]->OnDrawn();
		}
	}
}