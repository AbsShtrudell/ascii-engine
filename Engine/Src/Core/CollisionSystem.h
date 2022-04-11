#pragma once
#include "Collider.h"
#include <set>

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();

	void Update();
	void AddCollider(Collider* listener);
	void RemoveCollider(Collider* listener);

	static CollisionSystem* get();

private:
	void UpdateGravity(Collider* );
	void SolveStack(Collider* first, Collider* second);
	bool isSamePoints(Collider* first, Collider* second);
	bool isSameX(Collider* first, Collider* second);
	bool isSameY(Collider* first, Collider* second);
	bool isOnSurface(Collider* first);
	CollideType getRelations(Collider* first, Collider* second);

	std::map<Collider*, Collider*>CollidersList;

};

