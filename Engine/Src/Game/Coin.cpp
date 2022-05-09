#include "Coin.h"

Coin::Coin()
{
	LoadSprite("Resources\\MarioBrosSprites\\coin.spr");
	collider = new Collider(getSize(), this);

	collider->setSimulatePhysics(false);
	collider->setCollisionSet(CollisionSet::collisionSet_OverlapAll);
	collider->setCollideObjType(CollideObj::DYNAMIC);
}

Coin::~Coin()
{
	delete collider;
}
