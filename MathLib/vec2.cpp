#include "vec2.h"
#include <climits>
#include <cmath>
#include <cfloat>
#include <iostream>

vec2 operator + (const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;

	//return{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
	
	lhs = lhs + rhs;

	return lhs;
}

bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && 
		abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}

	return false;
}

vec2 operator && (const vec2 &lhs, const vec2 &rhs)
{

	if (lhs.x = rhs.x)
	{
		if (lhs.y = rhs.y)
		{
			std::cout << "Equal" << std::endl;
			
		}
	}
	else
	{
		std::cout << "not equal" << std::endl;
	}
}