#pragma once
#include <iostream>
#include <Core/Object.h>
#include <Core/IDrawObj.h>

class Text : protected IDrawObj, public Object
{
public:

	Text(std::wstring text, int color = 7);
	Text();
	~Text();

	virtual void OnDrawn() override;

	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture getTexture() override;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;

	virtual void setZOrder(int newValue) override;
	virtual void setVisibility(bool visibility) override;
	void setText(std::wstring text);
	void setColor(int value);

private:
	Texture* textSprite = nullptr;
	int color = 7;
};

