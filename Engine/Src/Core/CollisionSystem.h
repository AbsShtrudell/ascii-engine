#pragma once
#include "IColliderResp.h"
#include <set>

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();

	void Update();
	void AddCollider(IColliderResp* listener);
	void RemoveCollider(IColliderResp* listener);

	static CollisionSystem* get();

private:
	void UpdateGravity(IColliderResp* );
	void SolveStack(IColliderResp* first, IColliderResp* second);
	bool isSamePoints(IColliderResp* first, IColliderResp* second);
	bool isSameX(IColliderResp* first, IColliderResp* second);
	bool isSameY(IColliderResp* first, IColliderResp* second);
	bool isOnSurface(IColliderResp* first);
	CollideType getRelations(IColliderResp* first, IColliderResp* second);

	std::map<IColliderResp*, IColliderResp*>CollidersList;

};

