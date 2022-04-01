#pragma once

#include "Vec2.h"
#include "InputSystem/InputSystem.h"
#include <vector>

class Object;

class Object: public InputListener
{
public:

	Object();
	Object(Vec2 Location, Object* owner = NULL);
	~Object();

	const Vec2 GetWorldLocation();
	const Vec2 GetRelativeLocation();
	
	Vec2 SetLocation(Vec2 vector);
	Vec2 AddLocation(Vec2 vector);
	Vec2 AddLocation(int x, int y);

	Object* GetOwner() const;
	void AttachChild(Object* child);
	void DeattachChild(Object* child);
	static void Attach(Object* owner, Object* child);
	static void Deattach(Object* owner, Object* child);

	virtual void OnKeyDown(int key) override;
	virtual void OnKeyUp(int key) override;

	virtual void OnUpdate() {};

	static std::vector<Object*> GetAllObjects();

	template <typename T> 
	static std::vector<T*> GetAllObjectsOfClass();

private:
	void SetOwner(Object* owner);

	static std::vector<Object*> AllObjects;

	std::vector<Object*> ChildrenList;
	Object* Owner = nullptr;
	Vec2 Location = Vec2(0,0);
};

template <typename T>
static std::vector<T*> Object::GetAllObjectsOfClass()
{
	std::vector<T*> OutputObjectList;
	T* tempObj = nullptr;
	for (size_t i = 0; i < GetAllObjects().size(); i++)
	{
		tempObj = dynamic_cast<T*>(GetAllObjects()[i]);
		if (tempObj != NULL)
			OutputObjectList.push_back(tempObj);
	}
	return OutputObjectList;
}
