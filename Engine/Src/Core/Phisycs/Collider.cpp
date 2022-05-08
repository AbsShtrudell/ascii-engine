#include "Collider.h"
#include <CollisionSystem/CollisionSystem.h>

Collider::Collider(Vec2 sz, Object* owner)
{
	collisionSet = new CollisionSet;
	shape = new Matrix<bool>(sz, true);

	CollisionSystem::get()->AddCollider(this);

	if (owner != NULL)
	{
		Object::Attach(owner, this);
	}
}

Collider::~Collider()
{
	delete collisionSet;
	delete shape;
}

const Matrix<bool>* Collider::getShape()
{
	return shape;
}

CollisionSet* Collider::getCollisionSet()
{
	return collisionSet;
}

const bool Collider::isSimulatePhysics()
{
	return simulatePhysics;
}

const bool Collider::isCollisionEnabled()
{
	return enableCollision;
}

const CollideObj Collider::getCollideObjType()
{
	return collideObjType;
}

const Vec2 Collider::getVelocity()
{
	return velocity;
}

const Vec2 Collider::getSize()
{
	return shape->getSize();
}

void Collider::setShape(Matrix<bool> shp)
{
	*shape = shp;
}

void Collider::setCollisionSet(CollisionSet collset)
{
	*collisionSet = collset;
}

void Collider::setSimulatePhysics(bool value)
{
	simulatePhysics = value;
}

void Collider::setCollisionEnabled(bool value)
{
	enableCollision = value;
}

void Collider::setCollideObjType(CollideObj type)
{
	collideObjType = type;
}

void Collider::setVelocity(Vec2 vel)
{
	velocity = vel;
}

void Collider::setSize(Vec2 sz)
{
	shape->setSize(sz);
}

void Collider::OnCollide(Collider* obj)
{
}

void Collider::UpdateGravity(Vec2 direction)
{
	getOwner()->addLocation(direction);
}


