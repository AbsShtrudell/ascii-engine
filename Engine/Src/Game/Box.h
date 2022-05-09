#pragma once
#include <Core/Physics/Collider.h>
#include <Core/Sprite.h>
class Box : public Sprite
{
public:
	Box();
	~Box();

private:
	Collider* collider;
};

