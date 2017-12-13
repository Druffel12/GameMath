#pragma once
#include "Objects.h"
#include "Transform.h"
#include "Collision.h"



class Collider
{
public:
	AABB box;

	AABB getGlobalBox(const Transform &t) const;

	Collider(const AABB &a_box = { { 0,0 },{ .5,.5 } }) : box(a_box)
	{

	}
};


class CircleCollider
{
public:
	circle cir;

	circle getGlobalCircle(const Transform &t) const;

	CircleCollider(const circle &a_cir = { { 0,0 },.5 } ): cir(a_cir)
	{

	}
};

Collision collides(const Transform &At, const Collider &Ac,
	const Transform &Bt, const Collider &Bc);

Collision collides(const Transform &At, const CircleCollider &Ac,
	const Transform &Bt, const Collider &Bc);