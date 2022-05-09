#include "Coin.h"

Coin::Coin()
{
	LoadSprite("Resources\\MarioBrosSprites\\coin.spr");
	collider = new Collider(getSize(), this);

	collider->setSimulatePhysics(false);
	collider->setCollisionSet(CollisionSet::collisionSet_OverlapOnlyPawn);
	collider->setCollideObjType(CollideObj::DYNAMIC);
}

Coin::~Coin()
{
}
