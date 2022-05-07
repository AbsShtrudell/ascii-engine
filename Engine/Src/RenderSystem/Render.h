#pragma once
#include <Windows.h>
#include <Core/Camera.h>
#include <Core/IDrawObj.h>
#include <Console/Console.h>
#include <Math/Matrix.h>


enum class MatrixEnum { SYMBOL_MATRIX, SYMBOL_MATRIX_BUFF };


class Camera;

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
	void Draw(Vec2 location, IDrawObj* drawObj);

	const Vec2 getScreenSize() const;

	void setCamera(Camera* cam);
private:
	Matrix<CSymb> *SymbolMatrix, *BuffSymbolMatrix;

	Vec2 screenSize = Vec2(85, 30);
	ASCII::Console console;
	Camera* camera = nullptr;
};