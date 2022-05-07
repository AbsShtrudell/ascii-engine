#include "CollisionSystem.h"

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::Update()
{
	std::map<Collider*, Collider*>::iterator it = CollidersList.begin();
	std::map<Collider*, Collider*>::iterator it1;
	while (it != CollidersList.end())
	{
		it1 = CollidersList.begin();
		if (it->second->isCollisionEnabled())
		{
			while (it1 != CollidersList.end())
			{
				if (it->second != it1->second)
				{
					if (it1->second->isCollisionEnabled())
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
		if (it->second->isSimulatePhysics())UpdateGravity(it->second);
		it++;
	}
}

void CollisionSystem::AddCollider(Collider* listener)
{
	std::map<Collider*, Collider*>::iterator it = CollidersList.find(listener);
	if (it == CollidersList.end())
	{
		CollidersList.insert(std::make_pair<Collider*, Collider*>
			(std::forward<Collider*>(listener), std::forward<Collider*>(listener)));
	}
}

void CollisionSystem::RemoveCollider(Collider* listener)
{
	std::map<Collider*, Collider*>::iterator it = CollidersList.find(listener);

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

void CollisionSystem::UpdateGravity(Collider* collider)
{
	if (!isOnSurface(collider))
	{
		collider->UpdateGravity(isBlocked(collider, collider->getVelocity() + Vec2(0, 1)).second);
		collider->setVelocity(collider->getVelocity() + Vec2(0, 1));
	}
	else collider->setVelocity(Vec2(0, 0));
	
}

void CollisionSystem::SolveStack(Collider* first, Collider* second)
{
}

bool CollisionSystem::isSamePoints(Collider* first, Collider* second)
{
	if (second->getWorldLocation().x == first->getWorldLocation().x && second->getWorldLocation().y == first->getWorldLocation().y) return true;
	if (isSameX(first, second) && isSameY(first, second)) return true;
	else return false;
}

bool CollisionSystem::isSameX(Collider* first, Collider* second)
{
	int x2 = second->getWorldLocation().x;
	int x1 = first->getWorldLocation().x;
	if (second->getWorldLocation().x > first->getWorldLocation().x)
	{
		if (first->getWorldLocation().x + first->getSize().x - 1>= second->getWorldLocation().x) return true;
		else return false;
	}
	else
	{
		if (second->getWorldLocation().x + second->getSize().x - 1 >= first->getWorldLocation().x) return true;
		else return false;
	}
	return true;
}

bool CollisionSystem::isSameY(Collider* first, Collider* second)
{
	if (second->getWorldLocation().y > first->getWorldLocation().y)
	{
		if (first->getWorldLocation().y + first->getSize().y - 1>= second->getWorldLocation().y) return true;
		else return false;
	}
	else
	{
		if (second->getWorldLocation().y + second->getSize().y - 1 >= first->getWorldLocation().y) return true;
		else return false;
	}
	return true;
}

bool CollisionSystem::isOnSurface(Collider* first)
{
	std::map<Collider*, Collider*>::iterator it = CollidersList.begin();
	while (it != CollidersList.end())
	{
		if (it->second != first)
		{
			if (getRelations(it->second, first) == CollideType::BLOCK)
			{
				if (isSameX(first, it->second))
				{
					if (abs(it->second->getWorldLocation().y - (first->getWorldLocation().y + first->getSize().y - 1)) - 1 == 0)
					{
						return true;
					}
				}
			}
		}
		it++;
	}
	return false;
}

std::pair<bool, Vec2> CollisionSystem::isBlocked(Collider* collider, Vec2 direction)
{
	bool isBlock = false;
	std::map<Collider*, Collider*>::iterator it = CollidersList.begin();
	while (it != CollidersList.end())
	{
		if (it->second != collider)
		{
			if (getRelations(it->second, collider) == CollideType::BLOCK)
			{
				if (direction.y != 0)
				{
					if (isSameX(collider, it->second))
					{
						if (direction.y > 0)
						{
							int distance = abs(it->second->getWorldLocation().y - (collider->getWorldLocation().y + collider->getSize().y - 1)) - 1;
							if (direction.y >= distance)
							{

								direction.y = distance;
								isBlock = true;
							}
						}
						else
						{
							int distance = abs(collider->getWorldLocation().y - (it->second->getWorldLocation().y + it->second->getSize().y - 1)) - 1;
							if (abs(direction.y) >= distance)
							{
								direction.y = -1 * distance;
								isBlock = true;
							}
						}
					}
				}
				if (direction.x != 0)
				{
					if (isSameY(collider, it->second))
					{
						if (direction.x > 0)
						{
							int distance = abs(it->second->getWorldLocation().x - (collider->getWorldLocation().x + collider->getSize().x - 1)) - 1;
							if (direction.x >= distance)
							{
								direction.x = distance;
								isBlock = true;
							}
						}
						else
						{
							int distance = abs(collider->getWorldLocation().x - (it->second->getWorldLocation().x + it->second->getSize().x - 1)) - 1;
							if (abs(direction.x) >= distance)
							{
								direction.x = -1 * distance;
								isBlock = true;
							}
						}
					}
				}
			}
		}
		it++;
	}
	return std::pair<bool, Vec2>(isBlock, direction);
}

CollideType CollisionSystem::getRelations(Collider* first, Collider* second)
{
	return first->getCollisionSet()->getCollideType(second->getCollideObjType());
}
