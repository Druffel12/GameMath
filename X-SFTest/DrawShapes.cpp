#include "..\Physics\DrawShapes.h"
#include "sfwdraw.h"
void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawVecLine(const vec2 &a, const vec2 &b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, MAGENTA);
}

void drawAABB(const AABB & box, int color)
{
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position + box.extents;
	vec2 BR = { TR.x, BL.y };

	drawVecLine(TL, TR);
	drawVecLine(TR, BR);
	drawVecLine(BR, BL);
	drawVecLine(BL, TL);
}
