#pragma once

#include <fstream>
#include "Object.h"

class Sprite;

static std::vector<Sprite*> AllSprites;

class Sprite: public Object
{
public:

	Sprite(int w, int h, std::string path);
	Sprite();
	~Sprite();
	//Sprite(const Sprite& sprite);

	const Vector2 GetSize();
	const int GetZOrder();
	const int GetCurrentFrame();
	static std::vector<Sprite*> GetAllSprites();

	
	void LoadFrame(std::string path, int frame);
	int SetZOrder(int newValue);
	void SetSize(Vector2 sz);
	void SetSize(int x, int y);
	void SetFrame(int frame);

	int NextFrame();

	void ZSort();

	std::vector<wchar_t**> frames;
	bool Visible = true;
	bool Animate = true;
	
private:
	
	void ClearFrame(int frame);

	int currentFrame = 0;
	Vector2 size = Vector2(0, 0);
	int Z = 0;
};

