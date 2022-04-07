#pragma once

#include "Object.h"
#include "IDrawObj.h"
#include "../Matrix.h"
#include "../FileManagment/TextureReader.h"
#include "../FileManagment/TextureWriter.h"

class Sprite : protected IDrawObj, public Object
{
public:
	Sprite(std::string path);
	Sprite();
	~Sprite();

	virtual void OnDrawn() override;

	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture* getTexture() override;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;

	virtual void setZOrder(int newValue) override;
	virtual void setSize(Vec2 sz) override;
	virtual void setSize(int x, int y) override;
	virtual void setVisibility(bool visibility) override;

	void LoadSprite(std::string path);
	void SaveSprite(std::string path);

	
private:
	Texture* texture = nullptr;
};