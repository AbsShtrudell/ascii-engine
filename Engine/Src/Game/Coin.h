#pragma once
#include <Core/Sprite.h>
#include <Core/Object.h>
#include <Core/Phisycs/Collider.h>

class Coin : public Object
{
public:
	Coin();
	~Coin();

private:
	Sprite* sprite;
	Collider* collider;
};

