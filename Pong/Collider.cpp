#include "Collider.h"
#include "Objects.h"

Collision collides(const Transform & At, const Collider & Ac,
	const Transform & Bt, const Collider & Bc)
{
	return instersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}

Collision collides(const Transform & At, const CircleCollider & Ac, const Transform & Bt, const Collider & Bc)
{
	return intersect_circle_AABB(Ac.getGlobalCircle(At), Bc.getGlobalBox(Bt));
}

AABB Collider::getGlobalBox(const Transform & t) const
{
	auto retval = t.getGlobalTransform() * box;
	return retval;
}

circle CircleCollider::getGlobalCircle(const Transform & t) const
{
	return t.getGlobalTransform() * cir;
}
