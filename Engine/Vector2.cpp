#include "Vector2.h"

Vector2 Vector2::Sum(int x, int y)
{
	Vector2::X += x; Vector2::Y += y;
	return *this;
}

Vector2 Vector2::Sum(Vector2 vector)
{
	X += vector.X; Y += vector.Y;
	return *this;
}

Vector2 Vector2::Set(int x, int y)
{
	Vector2::X = x; Vector2::Y = y;
	return *this;
}