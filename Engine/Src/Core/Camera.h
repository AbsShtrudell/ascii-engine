#pragma once
#include <Core/Object.h>
#include <System/Delegate.h>

class Camera : public Object
{
public:
	Camera(Object* owner = NULL);
	~Camera();

public:
	Delegate<int> onDestroyed;
};

