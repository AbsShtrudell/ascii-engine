#include "Collider.h"

Collider::Collider(Vec2 sz)
{
	collisionSet = new CollisionSet;
	shape = new Matrix<bool>(sz, true);
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

void Collider::setCollideSet(CollisionSet collset)
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
	vel = velocity;
}

void Collider::setSize(Vec2 sz)
{
	shape->setSize(sz);
}


