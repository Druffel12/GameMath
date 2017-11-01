#pragma once
#include "shapes.h"
#include "Transform2.h"
#include "Collision.h"

class Collider
{
public:
	AABB box;

	AABB getGlobalBox(const Transform2 &t) const
	{
		return t.getGlobalTransform() * box;
	}

	Collider(const AABB &a_box = { { 0,0 },{ 1,1 } }) : box(a_box)
	{

	}
};


Collision collides(const Transform2 &At, const Collider &Ac,
	const Transform2 &Bt, const Collider &Bc);