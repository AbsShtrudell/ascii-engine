#pragma once
#include <Core/Sprite.h>
#include <Core/Object.h>
#include <Core/Phisycs/Collider.h>

class Coin : public Sprite
{
public:
	Coin();
	~Coin();

private:
	Collider* collider;
};

