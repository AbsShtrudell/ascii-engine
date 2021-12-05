#include "Object.h"

Object::Object()
{
	AllObjects.push_back(this);
	InputSystem::Get()->AddListener(this);
}

Object::Object(Vector2 Location)
{
	SetLocation(Location);
	AllObjects.push_back(this);
	InputSystem::Get()->AddListener(this);
}

Object::~Object()
{
	for(size_t i = 0 ; i < AllObjects.size();i++)
		if (this == AllObjects[i])
		{
			AllObjects.erase(AllObjects.begin() + i);
			break;
		}
	InputSystem::Get()->RemoveListener(this);
}

const Vector2 Object::GetLocation()
{
	if (Owner == NULL) return Location;
	else return Vector2(Location.X + GetOwner()->Location.X, Location.Y + GetOwner()->Location.Y);
}

Vector2 Object::SetLocation(Vector2 vector)
{
	Location = vector;
	return Location;
}

Vector2 Object::AddLocation(Vector2 vector)
{
	Location.Sum(vector);
	return Location;
}

Vector2 Object::AddLocation(int x, int y)
{
	Location.Sum(x, y);
	return Location;
}

void Object::SetOwner(Object* owner)
{
	Owner = owner;
}

Object* Object::GetOwner()
{
	return Owner;
}

void  Object::Attach(Object* owner, Object* child)
{
	if (child->GetOwner() != NULL)
	{
		if (child->GetOwner() == owner) return;
		Deattach(child->GetOwner(), child);
	}
	owner->ChildrenList.push_back(child);
	child->SetOwner(owner);
}

void Object::Deattach(Object* owner, Object* child)
{
	if (child->GetOwner() == NULL || child->GetOwner() != owner) return;

	for (size_t i = 0; i < ChildrenList.size(); i++)
		if (child == ChildrenList[i])
		{
			ChildrenList.erase(ChildrenList.begin() + i);
			break;
		}
	child->SetOwner(NULL);
}

std::vector<Object*> Object::GetAllObjects()
{
	return AllObjects;
}

void Object::OnKeyDown(int key)
{
	switch (key)
	{
	case'W':
		AddLocation(0, -1);
		break;
	case'S':
		AddLocation(0, 1);
		break;
	case'A':
		AddLocation(-1, 0);
		break;
	case'D':
		AddLocation(1, 0);
		break;
	}
}

void Object::OnKeyUp(int key)
{
}