#pragma once
#include <Core/Pawn.h>
#include <Core/Phisycs/Collider.h>
#include <Core/Camera.h>
#include <Game/PlayerAnimator.h>
#include <Core/Sprite.h>

class Player : public Pawn
{
public:
	Player();
	~Player();

	void OnUpdate() override;
	void OnKeyDown(int key) override;
	void OnKeyUp(int key) override;

private:
	PlayerAnimator* animator;
	Collider* collider;
	Camera* camera;

	int speed = 5;
	bool dead = false;
};

