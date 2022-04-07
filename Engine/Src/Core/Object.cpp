#include "Object.h"

Object::Object()
{
	AllObjects.push_back(this);
	InputSystem::Get()->AddListener(this);
}

Object::Object(Vec2 Location, Object* owner)
{
	SetLocation(Location);
	AllObjects.push_back(this);
	InputSystem::Get()->AddListener(this);
	if (owner != NULL) Attach(owner, this);
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

const Vec2 Object::GetWorldLocation()
{
	if (Owner == NULL) return Location;
	else return Vec2(Location.x + GetOwner()->Location.y, Location.y + GetOwner()->Location.y);
}

const Vec2 Object::GetRelativeLocation()
{
	return Location;
}

Vec2 Object::SetLocation(Vec2 vector)
{
	Location = vector;
	return Location;
}

Vec2 Object::AddLocation(Vec2 vector)
{
	Location.Add(vector);
	return Location;
}

Vec2 Object::AddLocation(int x, int y)
{
	Location.Add(x, y);
	return Location;
}

void Object::SetOwner(Object* owner)
{
	Owner = owner;
}

Object* Object::GetOwner() const
{
	return Owner;
}

void Object::AttachChild(Object* child)
{
	if (child->GetOwner() != NULL)
	{
		if (child->GetOwner() == this) return;
		Deattach(child->GetOwner(), child);
	}
	ChildrenList.push_back(child);
	child->SetOwner(this);
}

void Object::DeattachChild(Object* child)
{
	if (child->GetOwner() == NULL || child->GetOwner() != this) return;

	for (size_t i = 0; i < ChildrenList.size(); i++)
		if (child == ChildrenList[i])
		{
			ChildrenList.erase(ChildrenList.begin() + i);
			break;
		}
	child->SetOwner(NULL);
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

	for (size_t i = 0; i < owner->ChildrenList.size(); i++)
		if (child == owner->ChildrenList[i])
		{
			owner->ChildrenList.erase(owner->ChildrenList.begin() + i);
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

std::vector<Object*> Object::AllObjects;