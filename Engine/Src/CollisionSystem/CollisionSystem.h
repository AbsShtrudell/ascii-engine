#pragma once
#include <Core/Physics/Collider.h>
#include <list>

class CollisionSystem
{
public:

	CollisionSystem();
	~CollisionSystem();

	static CollisionSystem* get();

	void AddCollider(Collider* listener);
	void RemoveCollider(Collider* listener);

	void Update();

	bool isOnSurface(Collider* collider);

private:

	void UpdateGravity(Collider* collider);
	void SolveStack(Collider* first, Collider* second);

	bool isCollide(Collider* first, Collider* second);
	std::pair<bool, Vec2> isBlocked(Collider* collider, Vec2 direction);
	CollideType getRelations(Collider* first, Collider* second);

	std::list<Collider*>CollidersList;
};

