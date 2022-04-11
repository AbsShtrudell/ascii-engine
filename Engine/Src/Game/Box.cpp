#include "Box.h"

Box::Box()
{
	LoadSprite("F:\\Projects\\VS Projects\\ASCIIEngine\\Resources\\Quad.spr");
	collider = new Collider(getSize(), this);
	collider->setCollisionSet(CollisionSet::collisionSet_BlockAll);
	collider->setSimulatePhysics(false);
}

Box::~Box()
{
	delete collider;
}
