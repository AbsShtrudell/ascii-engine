#pragma once
#include <Math/Matrix.h>
#include <Core/Physics/CollisionSet.h>
#include <Core/Object.h>
#include <System/Delegate.h>

class Collider : public Object
{
public:

	Collider(Vec2 sz,Object* owner = NULL);
	~Collider();

	const Matrix<bool>* getShape();
	CollisionSet* getCollisionSet();
	const bool isSimulatePhysics();
	const bool isCollisionEnabled();
	const CollideObj getCollideObjType();
	const Vec2 getVelocity();
	const Vec2 getSize();

	void setShape(Matrix<bool> shp);
	void setCollisionSet(CollisionSet collset);
	void setSimulatePhysics(bool value);
	void setCollisionEnabled(bool value);
	void setCollideObjType(CollideObj type);
	void setVelocity(Vec2 vel);
	void setSize(Vec2 sz);

	void OnCollide(Collider* obj);
	void UpdateGravity(Vec2 direction);

private:
	bool simulatePhysics = true;
	bool enableCollision = true;
	CollideObj collideObjType = CollideObj::STATIC;
	CollisionSet* collisionSet;
	Matrix<bool>* shape;
	Vec2 velocity = Vec2(0, 0);
public:
	Delegate<Collider*> onCollide;
};