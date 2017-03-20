#pragma once
#include "Vec2.h"

class Vec4
{
public:

	Vec4()
		:
		x(0),
		y(0),
		x2(0),
		y2(0)
	{}
	Vec4(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		x2 = c;
		y2 = d;
	}
	void operator=(Vec4 vec)
	{
		x = vec.x;
		y = vec.y;
		x2 = vec.x2;
		y2 = vec.y2;
	}
	Vec4 operator+(Vec2 _vec)
	{
		Vec4 newVec = *this;
		newVec.x += _vec.x;
		newVec.y += _vec.y;
		return newVec;
	}

	int x;
	int y;
	int x2;
	int y2;
};