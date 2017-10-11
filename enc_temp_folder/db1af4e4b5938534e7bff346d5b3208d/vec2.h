#pragma once

union vec2
{
	// access by array
	float v[2];

	// access by individual component 
	struct { float x, y; };
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);