#include "Collider.h"
#include "Objects.h"

Collision collides(const Transform & At, const Collider & Ac,
	const Transform & Bt, const Collider & Bc)
{
	return instersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}

AABB Collider::getGlobalBox(const Transform & t) const
{
	return t.getGlobalTransform() * *box;
}
