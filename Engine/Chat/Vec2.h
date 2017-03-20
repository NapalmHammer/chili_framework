#pragma once

class Vec2
{
public:

	Vec2()
		:
		x(0),
		y(0)
	{}
	Vec2(int a, int b)
	{
		x = a;
		y = b;
	}

	int x;
	int y;

	void operator+=(int n)
	{
		x += n;
		y += n;
	}

	void operator-=(int n)
	{
		x -= n;
		y -= n;
	}
	void operator=(Vec2 vec)
	{
		x = vec.x;
		y = vec.y;
	}
};