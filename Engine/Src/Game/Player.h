#pragma once
#include <Core/Pawn.h>
#include <Core/Physics/Collider.h>
#include <Core/Camera.h>
#include <Game/PlayerAnimator.h>
#include <Game/Coin.h>
#include <Game/UI.h>
#include <Game/Enemy.h>
#include <Core/Sprite.h>

class Player : public Pawn
{
public:
	Player();
	~Player();

	void OnUpdate() override;
	void OnKeyDown(int key) override;
	void OnKeyUp(int key) override;
	void OnCollide(Object* obj);

	void Dead();

private:
	PlayerAnimator* animator;
	Collider* collider;
	Camera* camera;
	UI* ui;
	int speed = 5;
	int coinsamount = 0;
	bool dead = false;
};

