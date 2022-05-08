#include "Box.h"

Box::Box()
{
	LoadSprite("Resources\\MarioBrosSprites\\block.spr");
	collider = new Collider(getSize(), this);
	collider->setCollisionSet(CollisionSet::collisionSet_BlockAll);
	collider->setSimulatePhysics(false);
}

Box::~Box()
{
	delete collider;
}
