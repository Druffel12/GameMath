#include "Shapes.h"
#include "sfwdraw.h"
#include "DrawShapes"

void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}
void drawAABB(const AABB &box);
{
	sfw::drawLine(a.x, a.y, b.x, b.y, MAGENTA);
}
void drawAABB(const AABB & box)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, Tl);
	DrawVecLine(TL, Bl);
	DrawVecLine(BL, BR);
	DrawVecLine(BR, TR);
}