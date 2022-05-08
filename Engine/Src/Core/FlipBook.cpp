#include "FlipBook.h"

FlipBook::FlipBook(Animation* anim, Object* owner)
{
	if (owner != NULL)
	{
		Attach(owner, this);
	}
	animation = anim;
}

FlipBook::~FlipBook()
{
	delete animation;
}

void FlipBook::OnDrawn()
{
	animation->Play();
}

const Vec2 FlipBook::getSize()
{
	return animation->getCurrentFrame()->getSize();
}

const int FlipBook::getZOrder()
{
	return Z;
}

Texture FlipBook::getTexture()
{
	return *animation->getCurrentFrame();
}

const Vec2 FlipBook::getDrawLoacation()
{
	return getWorldLocation();
}

const bool FlipBook::isVisible()
{
	return visible;
}

bool FlipBook::isRotated()
{
	return rotated;
}

void FlipBook::setZOrder(int newValue)
{
	Z = newValue;
}

void FlipBook::setVisibility(bool visibility)
{
	visible = visibility;
}
void FlipBook::setRotationState(bool value)
{
	rotated = value;
}

