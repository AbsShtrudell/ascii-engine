#pragma once

class Vector2
{
public:

	Vector2(int x, int y)
	{
		Vector2::X = x; Vector2::Y = y;
	}

	Vector2()
	{
		Vector2::X = 0; Vector2::Y = 0;
	}

	Vector2 Set(int x, int y);
	Vector2 Sum(int x, int y);
	Vector2 Sum(Vector2 vector);

	int X, Y;
};

