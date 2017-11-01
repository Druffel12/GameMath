#include "Collider.h"

Collision collides(const Transform2 & At, const Collider & Ac,
	const Transform2 & Bt, const Collider & Bc)
{
	return instersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}
