#include "CollisionSystem.h"
#include <algorithm>

CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::Update()
{
	for(const auto& collider1 : CollidersList)
	{
		if (collider1->isCollisionEnabled() && (collider1->getCollideObjType() != CollideObj::STATIC))
		{
			for (const auto& collider2 : CollidersList)
			{
				if (collider1 != collider2)
				{
					if (collider2->isCollisionEnabled())
					{
						if (getRelations(collider1, collider2) != CollideType::IGNORE_THIS)
						{
							if (isCollide(collider1, collider2))
							{
								if (getRelations(collider1, collider2) == CollideType::BLOCK)
								{
									SolveStack(collider1, collider2);
								}
								collider1->OnCollide(collider2);
							}
						}
					}
				}
			}
		}
		if (collider1->isSimulatePhysics())UpdateGravity(collider1);
	}
}

void CollisionSystem::AddCollider(Collider* listener)
{
	auto it = std::find(CollidersList.begin(), CollidersList.end(), listener);
	if (it == CollidersList.end())
	{
		CollidersList.push_back(listener);
	}
}

void CollisionSystem::RemoveCollider(Collider* listener)
{
	auto it = std::find(CollidersList.begin(), CollidersList.end(), listener);

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

bool CollisionSystem::isCollide(Collider* first, Collider* second)
{
	if (first->getWorldLocation().x < second->getWorldLocation().x + second->getSize().x &&
		first->getWorldLocation().x + first->getSize().x > second->getWorldLocation().x &&
		first->getWorldLocation().y < second->getWorldLocation().y + second->getSize().y &&
		first->getWorldLocation().y + first->getSize().y > second->getWorldLocation().y) return true;
	else return false;
}

bool CollisionSystem::isOnSurface(Collider* colllider)
{
	for(const auto& element : CollidersList)
	{
		if (element != colllider)
		{
			if (getRelations(element, colllider) == CollideType::BLOCK)
			{
				if (colllider->getWorldLocation().x < element->getWorldLocation().x + element->getSize().x &&
					colllider->getWorldLocation().x + colllider->getSize().x > element->getWorldLocation().x)
				{
					if (abs(element->getWorldLocation().y - (colllider->getWorldLocation().y + colllider->getSize().y - 1)) - 1 == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

std::pair<bool, Vec2> CollisionSystem::isBlocked(Collider* collider, Vec2 direction)
{
	bool isBlock = false;
	for(const auto& element : CollidersList)
	{
		if (element != collider)
		{
			if (getRelations(collider, element) == CollideType::BLOCK)
			{
				if (direction.y != 0)
				{
					if (collider->getWorldLocation().x < element->getWorldLocation().x + element->getSize().x &&
						collider->getWorldLocation().x + collider->getSize().x > element->getWorldLocation().x)
					{
						if (direction.y > 0)
						{
							int distance = abs(element->getWorldLocation().y - (collider->getWorldLocation().y + collider->getSize().y - 1)) - 1;
							if (direction.y >= distance)
							{

								direction.y = distance;
								isBlock = true;
							}
						}
						else
						{
							int distance = abs(collider->getWorldLocation().y - (element->getWorldLocation().y + element->getSize().y - 1)) - 1;
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
					if (collider->getWorldLocation().y < element->getWorldLocation().y + element->getSize().y &&
						collider->getWorldLocation().y + collider->getSize().y > element->getWorldLocation().y)
					{
						if (direction.x > 0)
						{
							int distance = abs(element->getWorldLocation().x - (collider->getWorldLocation().x + collider->getSize().x - 1)) - 1;
							if (direction.x >= distance)
							{
								direction.x = distance;
								isBlock = true;
							}
						}
						else
						{
							int distance = abs(collider->getWorldLocation().x - (element->getWorldLocation().x + element->getSize().x - 1)) - 1;
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
	}
	return std::pair<bool, Vec2>(isBlock, direction);
}

CollideType CollisionSystem::getRelations(Collider* first, Collider* second)
{
	return first->getCollisionSet()->getCollideType(second->getCollideObjType());
}
