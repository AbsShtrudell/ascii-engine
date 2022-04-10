#pragma once
#include "Collider.h"

class IColliderResp
{
public:
	IColliderResp();
	~IColliderResp();

	virtual void OnCollide(IColliderResp* obj) = 0;
	virtual void UpdateGravity(Vec2 direction) = 0;

	virtual const Vec2 getCollideLocation() = 0;

	virtual Collider* getCollider() = 0;

protected:
	Collider* collider = nullptr;
};

