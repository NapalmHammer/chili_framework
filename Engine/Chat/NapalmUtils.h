#pragma once
#include "Vec4.h"
#include "../Mouse.h"

static const bool CheckMouseIsIn(const Vec4& pos, const Mouse::Event& mE, const std::pair<int, int>& mP)
{
	if (mP.first >= pos.x && mP.first <= pos.x2)
	{
		if (mP.second >= pos.y && mP.second <= pos.y2)
		{
			return true;
		}
	}
	return false;
}