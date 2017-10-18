#pragma once
#include "vec3.h"

union mat3
{
	vec3 c[3];
	float m[9];
	float mm[3][3];

	vec3 &operator[](size_t idx); // column accessor
	const vec3 &operator[](size_t idx) const;

	static mat3 identity() // creates and returns an identity matrix.
	{
		return mat3{ 1,0,0,
					 0,1,0,
					 0,0,1 };
	}
	static mat3 zero() // creates and returns an identity matrix.
	{
		return mat3{ 0,0,0,
			0,0,0,
			0,0,0 };
	}
};

bool operator==(const mat3 &A, const mat3 &B);
mat3 operator+(const mat3 &A, const mat3 &B); // not really used
mat3 operator-(const mat3 &A, const mat3 &B); // not really used

mat3 operator*(const mat3 &A, const mat3 &b); // combine transformations
vec3 operator*(const mat3 &A, const vec3 &V); // apply transformation

mat3 transpose(const mat3 &A); // flip the rows and columns

// unknowns
float determinant(const mat3 &A);

mat3 inverse(const mat3 &A);

mat3 translate(const vec2 &t);

mat3 scale(const vec2 &s);

mat3 scale(float x, float y);

mat3 rotate(float deg);