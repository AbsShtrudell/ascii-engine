#pragma once
#include "../Matrix.h"
#include "CollisionSet.h"

class Collider
{
public:

	Collider(Vec2 sz);
	~Collider();

	const Matrix<bool>* getShape();
	CollisionSet* getCollisionSet();
	const bool isSimulatePhysics();
	const bool isCollisionEnabled();
	const CollideObj getCollideObjType();
	const Vec2 getVelocity();
	const Vec2 getSize();

	void setShape(Matrix<bool> shp);
	void setCollideSet(CollisionSet collset);
	void setSimulatePhysics(bool value);
	void setCollisionEnabled(bool value);
	void setCollideObjType(CollideObj type);
	void setVelocity(Vec2 vel);
	void setSize(Vec2 sz);

private:
	bool simulatePhysics = true;
	bool enableCollision = true;
	CollideObj collideObjType = CollideObj::STATIC;
	CollisionSet* collisionSet;
	Matrix<bool>* shape;
	Vec2 velocity = Vec2(0, 0);
};