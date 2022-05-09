#pragma once
#include <Core/Object.h>
#include <Core/Physics/Collider.h>
#include <Game/EnemyAnimator.h>
#include <Game/Player.h>

class Enemy : public Object
{
public:
	Enemy(Vec2 Location);
	~Enemy();

	void OnUpdate();

private:
	Collider* collider;
	EnemyAnimator* animator;
};

