#pragma once
#include <Windows.h>
#include "Core/Vec2.h"
#include "Core/Sprite.h"
#include "Console.h"

enum class MatrixEnum { SYMBOL_MATRIX, SYMBOL_MATRIX_BUFF, COLOR_MATRIX, COLOR_MATRIX_BUFF, BACKCOLOR_MATRIX, BACKCOLOR_MATRIX_BUFF };

class Render
{
public:
	Render();
	~Render();

	void Clear(MatrixEnum MatrixType);
	void ResizeAllMatrixes(Vec2 size);
	void ResizeMatrix(MatrixEnum MatrixType, Vec2 size);
	void UpdateScreen();
	void UpdateBuffMatrix();
	void Draw(Vec2 location, Sprite* sprite);
	void Draw(Vec2 location, Sprite* sprite, int frame);

	const Vec2 getScreenSize() const;

private:
	void Resize(wchar_t**& matrix, Vec2 size);
	void Resize(int**& matrix, Vec2 size);
	void FillMatrix(wchar_t** matrix, wchar_t symbol);
	void FillMatrix(int** matrix, int value);

	wchar_t **SymbolMatrix, **BuffSymbolMatrix;
	int **ColorMatrix, **BuffColorMatrix;
	int **BackColorMatrix, **BuffBackColorMatrix;

	Vec2 screenSize = Vec2(30, 30);
	ASCII::Console console;
};

