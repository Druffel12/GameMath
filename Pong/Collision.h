#pragma once
#include "mathutils.h"
#include "vec2.h"
#include <cmath>

struct AABB;
struct circle;

struct Collision
{
	float penetrationDepth;
	float handedness;
	vec2 axis;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision instersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

Collision intersect_circle(const circle &A, const circle &B);
Collision intersect_circle_AABB(const circle &A, const AABB &B);


void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity );

void dynamic_resolution(vec2 &Apos, vec2 &Avel, float Amass,
	vec2 &Bpos, vec2 & Bvel, float Bmass,
	const Collision & hit, float elasticity);