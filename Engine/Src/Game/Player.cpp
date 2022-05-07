#include "Player.h"
#include <CollisionSystem/CollisionSystem.h>

Player::Player()
{
	sprite = new Sprite("F:\\Projects\\VS Projects\\ASCIIEngine\\Resources\\mario.spr", this);
	collider = new Collider(sprite->getSize(), this);
	camera = new Camera(this);
}

Player::~Player()
{
}

Camera* Player::getCamera()
{
	return camera;
}

void Player::OnKeyDown(int key)
{
	switch (key)
	{
	case'W':
		if (CollisionSystem::get()->isOnSurface(collider))
		{
			addLocation(0, -1);
			collider->setVelocity(Vec2(0, -4));
		}
		break;
	case'S':
		break;
	case'A':
		addLocation(-1, 0);
		break;
	case'D':
		addLocation(1, 0);
		break;
	}
}
