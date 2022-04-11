#pragma once

#include "Object.h"
#include "Collider.h"
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

	Collider* getCollider();
	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture* getTexture() override;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;

	virtual void setZOrder(int newValue) override;
	virtual void setSize(Vec2 sz) override;
	virtual void setSize(int x, int y) override;
	virtual void setVisibility(bool visibility) override;

	virtual void OnKeyDown(int key) override;

	void LoadSprite(std::string path);
	void SaveSprite(std::string path);
	
private:
	Collider* collider = nullptr;
	Texture* texture = nullptr;
};