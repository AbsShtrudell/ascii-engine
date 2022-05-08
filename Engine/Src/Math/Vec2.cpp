#include "Vec2.h"

Vec2::Vec2() : x(0), y(0) 
{
}

Vec2::Vec2(int x, int y)
{
	this->x = x;
	this->y = y;
}

//Vec2::Vec2(const Vec2& vec)
//{
//	x = vec.x;
//	y = vec.y;
//}

Vec2::~Vec2()
{
}

Vec2 Vec2::Add(int x, int y)
{
	this->x += x;
	this->y += y;
	return *this;
}

Vec2 Vec2::Add(Vec2 vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vec2& Vec2::operator=(const Vec2 right)
{
	this->x = right.x;
	this->y = right.y;
	return *this;
}

bool Vec2::operator==(const Vec2& right)
{
	return (this->x == right.x) && (this->y == right.y);
}

Vec2& Vec2::operator+=(const Vec2& right)
{
	this->x += right.x;
	this->y += right.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& right)
{
	this->x -= right.x;
	this->y -= right.y;
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& right)
{
	this->x *= right.x;
	this->y *= right.y;
	return *this;
}

Vec2& Vec2::operator*=(const float& scale)
{
	this->x *= scale;
	this->y *= scale;
	return *this;
}

const Vec2 operator+(const Vec2& left, const Vec2& right)
{
	return Vec2(left.x + right.x, left.y + right.y);
}

const Vec2 operator-(const Vec2& left, const Vec2& right)
{
	return Vec2(left.x - right.x, left.y - right.y);
}

const Vec2 operator*(const Vec2& left, const Vec2& right)
{
	return Vec2(left.x * right.x, left.y * right.y);
}

const Vec2 operator*(const Vec2& left, const int& scale)
{
	return Vec2(left.x * scale, left.y * scale);
}
