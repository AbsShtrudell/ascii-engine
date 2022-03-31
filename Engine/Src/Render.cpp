#include "Render.h"

Render::Render()
{
	SymbolMatrix = nullptr;
	BuffSymbolMatrix = nullptr;
	ColorMatrix = nullptr;
	BuffColorMatrix = nullptr;
	BackColorMatrix = nullptr;
	BuffBackColorMatrix = nullptr;
}

Render::~Render()
{
	delete[] SymbolMatrix;
	delete[] BuffSymbolMatrix;
	delete[] ColorMatrix;
	delete[] BuffColorMatrix;
	delete[] BackColorMatrix;
	delete[] BuffBackColorMatrix;
}

void Render::Clear(MatrixEnum MatrixType)
{
	switch (MatrixType)
	{
	case MatrixEnum::SYMBOL_MATRIX:
		FillMatrix(SymbolMatrix, L' ');
		break;
	case MatrixEnum::SYMBOL_MATRIX_BUFF:
		FillMatrix(BuffSymbolMatrix, L' ');
		break;
	case MatrixEnum::COLOR_MATRIX:
		FillMatrix(ColorMatrix, 0);
		break;
	case MatrixEnum::COLOR_MATRIX_BUFF:
		FillMatrix(BuffColorMatrix, 0);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX:
		FillMatrix(BackColorMatrix, 0);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX_BUFF:
		FillMatrix(BuffBackColorMatrix, 0);
		break;
	}
}

void Render::ResizeAllMatrixes(Vec2 size)
{
	Resize(SymbolMatrix, size);
	Resize(BuffSymbolMatrix, size);
	Resize(ColorMatrix, size);
	Resize(BuffColorMatrix, size);
	Resize(BackColorMatrix, size);
	Resize(BuffBackColorMatrix, size);
	screenSize = size;
}

void Render::ResizeMatrix(MatrixEnum MatrixType, Vec2 size)
{
	switch (MatrixType)
	{
	case MatrixEnum::SYMBOL_MATRIX:
		Resize(SymbolMatrix, size);
		break;
	case MatrixEnum::SYMBOL_MATRIX_BUFF:
		Resize(BuffSymbolMatrix, size);
		break;
	case MatrixEnum::COLOR_MATRIX:
		Resize(ColorMatrix, size);
		break;
	case MatrixEnum::COLOR_MATRIX_BUFF:
		Resize(BuffColorMatrix, size);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX:
		Resize(BackColorMatrix, size);
		break;
	case MatrixEnum::BACKCOLOR_MATRIX_BUFF:
		Resize(BuffBackColorMatrix, size);
		break;
	}
	screenSize = size;
}

void Render::FillMatrix(wchar_t** matrix, wchar_t symbol)
{
	for (int i = 0; i < screenSize.y; i++)
		for (int j = 0; j < screenSize.x; j++)
			matrix[i][j] = symbol;
}

void Render::FillMatrix(int** matrix, int value)
{
	for (int i = 0; i < screenSize.y; i++)
		for (int j = 0; j < screenSize.x; j++)
			matrix[i][j] = value;
}

void Render::UpdateScreen()
{
	int counter = 0;
	LPWSTR screen = new WCHAR[screenSize.y * screenSize.x];
	for (int i = 0; i < screenSize.y; i++)
		for (int j = 0; j < screenSize.x; j++)
		{
			SymbolMatrix[i][j] = BuffSymbolMatrix[i][j];
			screen[counter] = SymbolMatrix[i][j];
			counter++;
		}
	screen[screenSize.y * screenSize.x - 1] = '\0';
	DWORD dwBytesWritten = 0;

	console.WriteConsoleSymbols(screen, screenSize.y * screenSize.x -100);
	delete[]screen;
}

void Render::Draw(Vec2 location, Sprite* sprite)
{
	for (size_t i = 0; i < sprite->GetSize().y; i++)
	{
		if (i + location.y >= screenSize.y || location.y + i < 0) continue;
		for (size_t j = 0; j < sprite->GetSize().x; j++)
		{
			if (j + location.x >= screenSize.x || location.x + j < 0) continue;
			BuffSymbolMatrix[i + location.y][j + location.x] = sprite->frames[0][i][j];
		}
	}
}

void Render::Draw(Vec2 location, Sprite* sprite, int frame)
{
	if (!(frame > sprite->frames.size() - 1))
		for (size_t i = 0; i < sprite->GetSize().y; i++)
		{
			if (i + location.y >= screenSize.y || location.y + i < 0) continue;
			for (size_t j = 0; j < sprite->GetSize().x; j++)
			{
				if (j + location.x >= screenSize.x || location.x + j < 0) continue;
				BuffSymbolMatrix[i + location.y][j + location.x] = sprite->frames[frame][i][j];
			}
		}
}

const Vec2 Render::getScreenSize() const
{
	return screenSize;
}

void Render::Resize(wchar_t**& matrix, Vec2 size)
{
	if (size.x == 0 || size.y == 0) return;

	wchar_t** buffmatrix = nullptr;

	buffmatrix = new wchar_t* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		//buffmatrix[i] = nullptr;
		buffmatrix[i] = new wchar_t[size.y];
	}

	FillMatrix(buffmatrix, L' ');

	if (matrix != NULL)
	{
		for (int i = 0; i < screenSize.x; i++)
			for (int j = 0; j < screenSize.y; j++)
				buffmatrix[i][j] = matrix[i][j];
	}
	matrix = buffmatrix;
	//delete[]buffmatrix;
}

void Render::Resize(int**& matrix, Vec2 size)
{
	if (size.x == 0 || size.y == 0) return;

	int** buffmatrix = nullptr;

	buffmatrix = new int* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		//buffmatrix[i] = nullptr;
		buffmatrix[i] = new int[size.y];
	}

	FillMatrix(buffmatrix, 7);

	if (matrix != NULL)
	{
		for (int i = 0; i < screenSize.x; i++)
			for (int j = 0; j < screenSize.y; j++)
				buffmatrix[i][j] = matrix[i][j];
	}
	matrix = buffmatrix;
	//delete[]buffmatrix;
}

void Render::UpdateBuffMatrix()
{
	Clear(MatrixEnum::SYMBOL_MATRIX);
	for (size_t i = 0; i < Sprite::GetAllSprites().size(); i++)
	{
		if (Sprite::GetAllSprites()[i]->Visible == true)
			if (Sprite::GetAllSprites()[i]->Animate == true)
				Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i], Sprite::GetAllSprites()[i]->NextFrame());
			else Draw(Sprite::GetAllSprites()[i]->GetLocation(), Sprite::GetAllSprites()[i]);
	}
}