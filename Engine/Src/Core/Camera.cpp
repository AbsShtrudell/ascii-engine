#include "Camera.h"

Camera::Camera(Object* owner)
{
	if (owner != NULL)
	{
		Attach(owner, this);
	}
}

Camera::~Camera()
{
	onDestroyed.Call(0);
}
