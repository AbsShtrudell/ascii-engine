#pragma once
#include <Core/Object.h>
#include <Core/IDrawObj.h>
#include <Core/Animation.h>

class Animator : protected IDrawObj, public Object
{
public:
	Animator();
	~Animator();

	virtual void OnDrawn() override;
	void OnUpdate() override;
	virtual void CheckAnimatorState() = 0;

	bool isRotated();
	const Animation* getCurrentAnimation();
	virtual const Vec2 getSize() override;
	virtual const int getZOrder() override;
	virtual Texture getTexture() override;
	virtual const Vec2 getDrawLoacation() override;
	virtual const bool isVisible() override;

	void setCurrentAnimation(Animation* animation, bool rotated);
	virtual void setZOrder(int newValue) override;
	virtual void setVisibility(bool visibility) override;
private:
	Animation* currentAnimation;
	bool rotated;
};

