#pragma once

#include <fstream>
#include "Object.h"
#include "../Matrix.h"

class Sprite : public Object
{
protected:

	class SpriteLoader
	{
	public:
		SpriteLoader();
		~SpriteLoader();

		static void LoadSprite(std::string path, Sprite& spr);
	};

public:

	Sprite(int w, int h, std::string path);
	Sprite();
	~Sprite();

	const Vec2 GetSize();
	const int GetZOrder();
	//const int GetCurrentFrame();
	static std::vector<Sprite*> GetAllSprites();

	//void LoadFrame(std::string path, int frame);
	int SetZOrder(int newValue);
	void SetSize(Vec2 sz);
	void SetSize(int x, int y);
	//void SetFrame(int frame);

	const bool isVisible() const;
	void setVisibility(bool visibility);

	//int NextFrame();

	static void ZSort();

	//std::vector<wchar_t**> frames;
	
private:

	//void ClearFrame(int frame);
	static std::vector<Sprite*> AllSprites;
	
	Matrix<wchar_t> symbolMatrix;
	Matrix<int> colorMatrix, backColorMatrix;
	bool Visible = true;
	//int currentFrame = 0;
	Vec2 size = Vec2(1, 1);
	int Z = 0;
};