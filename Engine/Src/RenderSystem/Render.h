#pragma once
#include <Windows.h>
#include <Core/Camera.h>
#include <Core/IDrawObj.h>
#include <Console/ConsoleWIN.h>
#include <Math/Matrix.h>


enum class RenderMatrix { SYMBOL_MATRIX, SYMBOL_MATRIX_BUFF };

class Render
{
public:
	Render();
	~Render();

	void Clear(RenderMatrix MatrixType);
	void ResizeScreen(Vec2 size);
	void UpdateScreen();
	void UpdateBuffMatrix();
	void Draw(Vec2 location, IDrawObj* drawObj);

	const Vec2 getScreenSize() const;

	void setCamera(class Camera* cam);
private:
	Matrix<CSymb> *SymbolMatrix, *BuffSymbolMatrix;

	Vec2 screenSize = Vec2(200, 50);
	ASCII::IConsole* console;
	Camera* camera = nullptr;
};