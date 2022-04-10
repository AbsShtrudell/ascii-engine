#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::Update()
{
	std::map<IColliderResp*, IColliderResp*>::iterator it = CollidersList.begin();
	std::map<IColliderResp*, IColliderResp*>::iterator it1;
	while (it != CollidersList.end())
	{
		it1 = CollidersList.begin();
		if (it->second->getCollider()->isCollisionEnabled())
		{
			while (it1 != CollidersList.end())
			{
				if (it->second != it1->second)
				{
					if (it1->second->getCollider()->isCollisionEnabled())
					{
						if (getRelations(it->second, it1->second) == CollideType::IGNORE_THIS)
						{
							if (isSamePoints(it->second, it1->second))
							{
								if (getRelations(it->second, it1->second) == CollideType::BLOCK)
								{
									SolveStack(it->second, it1->second);
								}
								it->second->OnCollide(it1->second);
							}
						}
					}
				}
				it1++;
			}
		}
		if (it->second->getCollider()->isSimulatePhysics())UpdateGravity(it->second);
		it++;
	}
}

void CollisionSystem::AddCollider(IColliderResp* listener)
{
	std::map<IColliderResp*, IColliderResp*>::iterator it = CollidersList.find(listener);
	if (it == CollidersList.end())
	{
		CollidersList.insert(std::make_pair<IColliderResp*, IColliderResp*>
			(std::forward<IColliderResp*>(listener), std::forward<IColliderResp*>(listener)));
	}
}

void CollisionSystem::RemoveCollider(IColliderResp* listener)
{
	std::map<IColliderResp*, IColliderResp*>::iterator it = CollidersList.find(listener);

	if (it != CollidersList.end())
	{
		CollidersList.erase(it);
	}
}

CollisionSystem* CollisionSystem::get()
{
	static CollisionSystem system;
	return &system;
}

void CollisionSystem::UpdateGravity(IColliderResp* collider)
{
	if (!isOnSurface(collider))
	{
		collider->UpdateGravity(collider->getCollider()->getVelocity() + Vec2(0, 1));
		collider->getCollider()->setVelocity(collider->getCollider()->getVelocity() + Vec2(0, 1));
	}
	else collider->getCollider()->setVelocity(Vec2(0, 0));
	
}

void CollisionSystem::SolveStack(IColliderResp* first, IColliderResp* second)
{
}

bool CollisionSystem::isSamePoints(IColliderResp* first, IColliderResp* second)
{
	if (second->getCollideLocation().x == first->getCollideLocation().x && second->getCollideLocation().y == first->getCollideLocation().y) return true;
	if (isSameX(first, second) && isSameY(first, second)) return true;
	else return false;
}

bool CollisionSystem::isSameX(IColliderResp* first, IColliderResp* second)
{
	if (second->getCollideLocation().x > first->getCollideLocation().x)
	{
		if (first->getCollideLocation().x + first->getCollider()->getSize().x >= second->getCollideLocation().x) return true;
		else return false;
	}
	else
	{
		if (second->getCollideLocation().x + second->getCollider()->getSize().x >= first->getCollideLocation().x) return true;
		else return false;
	}
	return true;
}

bool CollisionSystem::isSameY(IColliderResp* first, IColliderResp* second)
{
	if (second->getCollideLocation().y > first->getCollideLocation().y)
	{
		if (first->getCollideLocation().y + first->getCollider()->getSize().y >= second->getCollideLocation().y) return true;
		else return false;
	}
	else
	{
		if (second->getCollideLocation().y + second->getCollider()->getSize().y >= first->getCollideLocation().y) return true;
		else return false;
	}
	return true;
}

bool CollisionSystem::isOnSurface(IColliderResp* first)
{
	std::map<IColliderResp*, IColliderResp*>::iterator it = CollidersList.begin();
	while (it != CollidersList.end())
	{
		if (it->second != first)
		{
			if (getRelations(it->second, first) == CollideType::BLOCK)
			{
				if ((first->getCollideLocation().y + first->getCollider()->getSize().y - 1) - it->second->getCollideLocation().y == -1)
				{
					if (isSameX(first, it->second)) return true;
				}
			}
		}
		it++;
	}
	return false;
}

CollideType CollisionSystem::getRelations(IColliderResp* first, IColliderResp* second)
{
	return first->getCollider()->getCollisionSet()->getCollideType(second->getCollider()->getCollideObjType());
}
