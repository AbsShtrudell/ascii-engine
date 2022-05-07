#pragma once
#include <Core/Pawn.h>
#include <Core/Phisycs/Collider.h>
#include <Core/Camera.h>
#include <Core/Sprite.h>

class Player : public Pawn
{
public:
	Player();
	~Player();

	Camera* getCamera();

	void OnKeyDown(int key);

private:
	Sprite* sprite;
	Collider* collider;
	Camera* camera;
};

