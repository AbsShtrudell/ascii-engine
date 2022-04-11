#include "Camera.h"

Camera::Camera(Object* owner)
{
	if (owner != NULL)
	{
		Attach(owner, this);
	}
	setLocation(Vec2(-42, -10));
}

Camera::~Camera()
{
}
