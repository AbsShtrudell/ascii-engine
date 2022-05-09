#include "Enemy.h"

Enemy::Enemy(Vec2 Location)
{
	animator = new EnemyAnimator(this);
	collider = new Collider(animator->getSize(), this);

	collider->setCollideObjType(CollideObj::DYNAMIC);
	collider->setCollisionSet(CollisionSet::collisionSet_OverlapOnlyPawn);
	collider->setSimulatePhysics(true);

	collider->setVelocity(Vec2(-1, 0));
}

Enemy::~Enemy()
{
	delete animator;
	delete collider;
}

void Enemy::OnUpdate()
{
	addLocation(-1, 0);
}
