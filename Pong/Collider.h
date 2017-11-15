#pragma once
//#include "Objects.h"
#include "Transform.h"
#include "Collision.h"

class AABB;

class Collider
{
public:
	AABB *box;

	AABB getGlobalBox(const Transform &t) const;

	Collider(AABB *a_box) : box(a_box) {};
};


Collision collides(const Transform &At, const Collider &Ac,
	const Transform &Bt, const Collider &Bc);
