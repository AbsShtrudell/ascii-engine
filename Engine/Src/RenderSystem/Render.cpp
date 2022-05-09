#include "Render.h"

Render::Render()
{
	console = new ASCII::ConsoleWIN();

	SymbolMatrix = new Matrix<CSymb>(screenSize, { L' ' , 159});
	BuffSymbolMatrix = new Matrix<CSymb>(screenSize, { L' ', 159 });
}

Render::~Render()
{
}

void Render::Clear(RenderMatrix MatrixType)
{
	switch (MatrixType)
	{
	case RenderMatrix::SYMBOL_MATRIX:
		SymbolMatrix->Clear();
		break;
	case RenderMatrix::SYMBOL_MATRIX_BUFF:
		BuffSymbolMatrix->Clear();
		break;
	}
}

void Render::ResizeScreen(Vec2 size)
{
	SymbolMatrix->setSize(size);
	BuffSymbolMatrix->setSize(size);
	screenSize = size;
}

void Render::UpdateScreen()
{
	if (camera == NULL)
	{
		std::vector<Camera*> cameras = Object::getAllObjectsOfClass<Camera>();
		if (cameras.size() > 0) setCamera(cameras[0]);
	}

	int counter = 0;
	LPWSTR screen = new WCHAR[screenSize.y * screenSize.x];
	int* screenColor = new int[screenSize.y * screenSize.x];

	for (int i = 0; i < screenSize.y; i++)
		for (int j = 0; j < screenSize.x; j++)
		{
			SymbolMatrix->at(j, i) = BuffSymbolMatrix->at(j, i);
			screen[counter] = SymbolMatrix->at(j, i).symbol;
			screenColor[counter] = SymbolMatrix->at(j, i).color;
			counter++;
		}

	DWORD dwBytesWritten = 0;

	console->WriteConsoleSymbols(screen, screenSize.y * screenSize.x);
	console->WriteConsoleAttribute(screenColor, screenSize.y * screenSize.x);
	Clear(RenderMatrix::SYMBOL_MATRIX_BUFF);
	delete[]screen;
	delete[]screenColor;
}

void Render::Draw(Vec2 location, IDrawObj* drawObj)
{
	if (camera != NULL)
	{
		Texture texture = drawObj->getTexture();
		for (size_t i = 0; i < drawObj->getSize().x; i++)
		{
			if (i + location.x - camera->getWorldLocation().x >= screenSize.x || - camera->getWorldLocation().x + location.x + i < 0) continue;
			for (size_t j = 0; j < drawObj->getSize().y; j++)
			{
				if (j + location.y - camera->getWorldLocation().y >= screenSize.y || - camera->getWorldLocation().y + location.y + j < 0) continue;
				{
					BuffSymbolMatrix->at(-camera->getWorldLocation().x + i + location.x, -camera->getWorldLocation().y + j + location.y) = texture.at(i, j);
				}
			}
		}
	}
}

const Vec2 Render::getScreenSize() const
{
	return screenSize;
}

void Render::setCamera(Camera* cam)
{
	if (cam != NULL)camera = cam;
}

void Render::UpdateBuffMatrix()
{
	Clear(RenderMatrix::SYMBOL_MATRIX);
	IDrawObj::ZSort();
	for (size_t i = 0; i < IDrawObj::getAllDrawObjects().size(); i++)
	{
		if (IDrawObj::getAllDrawObjects()[i]->isVisible() == true)
		{
			Draw(IDrawObj::getAllDrawObjects()[i]->getDrawLoacation(), IDrawObj::getAllDrawObjects()[i]);
			IDrawObj::getAllDrawObjects()[i]->OnDrawn();
		}
	}
}