#pragma once

#include <Math/Vec2.h>
#include <vector>

class Object
{
public:

	Object();
	Object(Vec2 Location, Object* owner = NULL);
	virtual ~Object();

	const Vec2 getWorldLocation();
	const Vec2 getRelativeLocation();
	
	Vec2 setLocation(Vec2 vector);
	Vec2 addLocation(Vec2 vector);
	Vec2 addLocation(int x, int y);

	Object* getOwner() const;
	std::vector<Object*> getAllChilds();
	template <typename T>
	std::vector<T*> getAllChildsOfClass();
	void AttachChild(Object* child);
	void DeattachChild(Object* child);
	static void Attach(Object* owner, Object* child);
	static void Deattach(Object* owner, Object* child);

	virtual void OnUpdate() {};

	void Destroy();

	static std::vector<Object*> getAllObjects();
	static std::vector<Object*>& getDestroyedObjects();

	template <typename T> 
	static std::vector<T*> getAllObjectsOfClass();

private:
	void setOwner(Object* owner);

	static std::vector<Object*> AllObjects;
	static std::vector<Object*> DestroyedObjects;

	std::vector<Object*> ChildrenList;
	Object* Owner = nullptr;
	Vec2 Location = Vec2(0,0);
};

template<typename T>
inline std::vector<T*> Object::getAllChildsOfClass()
{
	std::vector<T*> OutputObjectList;
	T* tempObj = nullptr;
	for (size_t i = 0; i < ChildrenList.size(); i++)
	{
		tempObj = dynamic_cast<T*>(ChildrenList[i]);
		if (tempObj != NULL)
			OutputObjectList.push_back(tempObj);
	}
	return OutputObjectList;
}

template <typename T>
static std::vector<T*> Object::getAllObjectsOfClass()
{
	std::vector<T*> OutputObjectList;
	T* tempObj = nullptr;
	for (size_t i = 0; i < getAllObjects().size(); i++)
	{
		tempObj = dynamic_cast<T*>(getAllObjects()[i]);
		if (tempObj != NULL)
			OutputObjectList.push_back(tempObj);
	}
	return OutputObjectList;
}

