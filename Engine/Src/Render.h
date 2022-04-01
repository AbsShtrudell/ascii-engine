#pragma once
#include <Windows.h>
#include "Core/Vec2.h"
#include "Core/Sprite.h"
#include "Console.h"
#include "Matrix.h"

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
	Matrix<wchar_t> *SymbolMatrix, *BuffSymbolMatrix;
	Matrix<int> *ColorMatrix, *BuffColorMatrix;
	Matrix<int> *BackColorMatrix, *BuffBackColorMatrix;

	Vec2 screenSize = Vec2(85, 30);
	ASCII::Console console;
};