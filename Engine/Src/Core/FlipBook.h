#pragma once
#include <Core/Object.h>
#include <Core/IDrawObj.h>
#include <Core/Animation.h>

class FlipBook : protected IDrawObj, public Object
{
public:
	FlipBook(Animation* anim, Object* owner);
	~FlipBook();

	virtual void OnDrawn() override;

	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture getTexture() override;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;
	bool isRotated();

	virtual void setZOrder(int newValue) override;
	virtual void setVisibility(bool visibility) override;
	void setRotationState(bool value);

private:
	Animation* animation;
	bool rotated = false;
};

