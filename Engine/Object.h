#pragma once

#include "Vector2.h"
#include "InputSystem.h"
#include <vector>

class Object;

static std::vector<Object*> AllObjects;

class Object: public InputListener
{
public:

	Object();
	Object(Vector2 Location);
	~Object();

	const Vector2 GetLocation();
	
	Vector2 SetLocation(Vector2 vector);
	Vector2 AddLocation(Vector2 vector);
	Vector2 AddLocation(int x, int y);

	Object* GetOwner();
	void Attach(Object* owner, Object* child);
	void Deattach(Object* owner, Object* child);

	virtual void OnKeyDown(int key) override;
	virtual void OnKeyUp(int key) override;

	static void Save(Object object);

	static std::vector<Object*> GetAllObjects();
	template <typename T> static auto GetAllObjectsOfClass()
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

	void OnUpdate() {};

private:
	void SetOwner(Object* owner);
	virtual void EmptyFunc() {}; //empty function, that allows dynamic_cast (needs to be removed later)

	std::vector<Object*> ChildrenList;
	Object* Owner = nullptr;
	Vector2 Location = Vector2(0,0);
};

