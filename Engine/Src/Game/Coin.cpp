#include "Coin.h"

Coin::Coin()
{
	sprite = new Sprite("Resources\\MarioBrosSprites\\coin.spr", this);
	collider = new Collider(sprite->getSize(), this);

	collider->setSimulatePhysics(false);
	collider->setCollisionSet(CollisionSet::collisionSet_OverlapOnlyPawn);
}
