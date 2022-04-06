#pragma once

#include <fstream>
#include "Object.h"
#include "../CSymb.h"
#include "../Matrix.h"

class Sprite : public Object
{
protected:

	class SpriteReader
	{
	public:
		SpriteReader(){}
		~SpriteReader(){}

		static void LoadSprite(std::string path, Sprite* sprite);
	};

	class SpriteWriter
	{
	public:
		SpriteWriter(){}
		~SpriteWriter(){}

		static void WriteSprite(std::string path, Sprite* sprite);
	};

public:
	Sprite(std::string path);
	Sprite();
	~Sprite();

	const Vec2 getSize();
	const int getZOrder();
	Matrix<CSymb>* getSymbMatrix();
	const bool isVisible() const;
	static std::vector<Sprite*> getAllSprites();

	int setZOrder(int newValue);
	void setSize(Vec2 sz);
	void setSize(int x, int y);
	void setVisibility(bool visibility);

	void LoadSprite(std::string path);
	void SaveSprite(std::string path);

	static void ZSort();
	
private:
	static std::vector<Sprite*> AllSprites;
	
	Matrix<CSymb>* symbolMatrix;
	bool visible = true;
	Vec2 size = Vec2(1, 1);
	int Z = 0;
};