#include "IColliderResp.h"

IColliderResp::IColliderResp()
{
	collider = new Collider(Vec2(5, 1));
}

IColliderResp::~IColliderResp()
{
	delete collider;
}

Collider* IColliderResp::getCollider()
{
	return collider;
}
