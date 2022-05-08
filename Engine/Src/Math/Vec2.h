#pragma once

class Vec2
{
public:
	int x, y;

	Vec2();
	Vec2(int x, int y);
	//Vec2(const Vec2& vec);
	~Vec2();

	Vec2 Add(int x, int y);
	Vec2 Add(Vec2 vec);

	Vec2& operator=(const Vec2 right);
	bool operator==(const Vec2& right);

	Vec2& operator+=(const Vec2& right);
	Vec2& operator-=(const Vec2& right);
	Vec2& operator*=(const Vec2& right);
	Vec2& operator*=(const float& scale);

	friend const Vec2 operator+(const Vec2& left, const Vec2& right);
	friend const Vec2 operator-(const Vec2& left, const Vec2& right);
	friend const Vec2 operator*(const Vec2& left, const Vec2& right);
	friend const Vec2 operator*(const Vec2& left, const int& scale);
};

