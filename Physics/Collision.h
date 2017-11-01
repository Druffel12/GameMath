#pragma once
#include "mathutils.h"
#include "Shapes.h"
#include <cmath>

struct Collision
{
	float penetrationDepth;
	float handedness;
	vec2 axis;
};
Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision instersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit);
