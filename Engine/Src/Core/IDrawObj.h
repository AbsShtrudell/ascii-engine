#pragma once

#include <Math/Matrix.h>

class IDrawObj;

typedef std::vector<IDrawObj*> DrawObjects;

class IDrawObj
{
public:
	IDrawObj();
	~IDrawObj();

	virtual void OnDrawn() = 0;

	virtual Texture* getTexture() = 0;
	virtual const int getZOrder() = 0;
	virtual const Vec2 getSize() = 0;
	virtual const Vec2 getDrawLoacation() = 0;
	virtual const bool isVisible() = 0;

	virtual void setZOrder(int newValue) = 0;
	virtual void setSize(Vec2 sz) = 0;
	virtual void setSize(int x, int y) = 0;
	virtual void setVisibility(bool visibility) = 0;

	static void ZSort();
	static DrawObjects getAllDrawObjects();

protected:
	Vec2 size = Vec2(1, 1);
	bool visible = true;
	int Z = 0;

private:
	static DrawObjects AllDrawObjects;
};

