#include "Player.h"
#include <CollisionSystem/CollisionSystem.h>

Player::Player()
{
	animator = new PlayerAnimator(this);
	collider = new Collider(animator->getSize(), this);
	camera = new Camera(this);
}

Player::~Player()
{
}

Camera* Player::getCamera()
{
	return camera;
}

void Player::OnUpdate()
{
	animator->setOnGroundState(CollisionSystem::get()->isOnSurface(collider));
}

void Player::OnKeyDown(int key)
{
	switch (key)
	{
	case'W':
		if (CollisionSystem::get()->isOnSurface(collider))
		{
			addLocation(0, -1);
			collider->setVelocity(Vec2(0, -8));
		}
		break;
	case'S':
		break;
	case'A':
		animator->setMovingState(-1);
		addLocation(-1 * speed, 0);
		break;
	case'D':
		animator->setMovingState(1);
		addLocation(1 * speed, 0);
		break;
	}
}

void Player::OnKeyUp(int key)
{
	switch (key)
	{
	case'A':
		animator->setMovingState(0);
		break;
	case'D':
		animator->setMovingState(0);
		break;
	}
}
