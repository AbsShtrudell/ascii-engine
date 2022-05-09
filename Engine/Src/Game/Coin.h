#pragma once
#include <Core/Sprite.h>
#include <Core/Object.h>
#include <Core/Physics/Collider.h>

class Coin : public Sprite
{
public:
	Coin();
	~Coin();

private:
	Collider* collider;
};

