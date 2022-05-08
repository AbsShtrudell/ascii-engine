#pragma once
#include <Core/Phisycs/Collider.h>
#include <set>

class CollisionSystem
{
public:
	CollisionSystem();
	~CollisionSystem();

	void Update();
	void AddCollider(Collider* listener);
	void RemoveCollider(Collider* listener);

	bool isOnSurface(Collider* first);

	static CollisionSystem* get();

private:
	void UpdateGravity(Collider* );
	void SolveStack(Collider* first, Collider* second);
	bool isCollide(Collider* first, Collider* second);
	std::pair<bool, Vec2> isBlocked(Collider* collider, Vec2 direction);
	CollideType getRelations(Collider* first, Collider* second);

	std::map<Collider*, Collider*>CollidersList;

};

