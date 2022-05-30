#include "Player.h"
#include <CollisionSystem/CollisionSystem.h>

Player::Player()
{
	animator = new PlayerAnimator(this);
	animator->setZOrder(5);
	collider = new Collider(animator->getSize(), this);
	collider->setCollideObjType(CollideObj::PAWN);
	collider->setCollisionSet(CollisionSet::collisionSet_OverlapAll);
	collider->setSimulatePhysics(true);
	collider->onCollide.Bind(std::bind(&Player::OnCollide, this, std::placeholders::_1));
	camera = new Camera(this);
	ui = new UI;
	camera->AttachChild(ui);
	camera->setLocation(Vec2(-40, -30));
}

Player::~Player()
{
}

void Player::OnUpdate()
{
	if (getWorldLocation().y > 16) Dead();
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
	case 32:
		if (dead)
		{
			onEndLevel.Call(coinsamount);
		}
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

void Player::OnCollide(Object* obj)
{
	Coin* coin = dynamic_cast<Coin*>(obj->getOwner());
	if (coin != nullptr)
	{
		coinsamount++;
		ui->setCoinsCounterText(std::wstring(std::to_wstring(coinsamount)));
		coin->Destroy();
		return;
	}
	Enemy* enemy = dynamic_cast<Enemy*>(obj->getOwner());
	if (enemy != nullptr)
	{
		if (-enemy->getWorldLocation().y < -this->getWorldLocation().y)
		{
			coinsamount++;
			ui->setCoinsCounterText(std::wstring(std::to_wstring(coinsamount)));
			enemy->Destroy();
		}
		else
			Dead();
		return;
	}
}

void Player::Dead()
{
	if (!dead)
	{
		camera->setLocation(camera->getWorldLocation());
		DeattachChild(camera);
		dead = true;
		addLocation(0, -1);
		collider->setVelocity(Vec2(0, -8));
		collider->setCollisionSet(CollisionSet::collisionSet_IgnoreAll);
		collider->setCollisionEnabled(false);
		animator->setDeathState(dead);
		ui->setGameOverState(true);
	}
}
