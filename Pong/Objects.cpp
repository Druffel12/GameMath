#include "Objects.h"
#include "sfwdraw.h"
#include <cmath>
#include "Ball.h"
void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void Draw(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void Ball::update(float dt)
{
	Pong.force += {10, 0};
	//ballCollider.cir.position = ballTransform.getGlobalTransform().c[2].xy;
	Pong.integrate(ballTransform, dt);
}

void Ball::Draw()
{
	sfw::drawCircle(ballTransform.position.x, ballTransform.position.y, (ballCollider.box.extents.x + ballCollider.box.extents.y) / 2, 12, MAGENTA);
}
 
void drawLine(float BLX = 0, float BLY = 5, float BRX = 800, float BRY = 5)
{
	sfw::drawLine(BLX, BLY, BRX, BRY);
}


circle operator*(const mat3 & M, const circle & C)
{
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = mag(M[0].xy);
	scale.y = mag(M[1].xy);
	// average?

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;

}
AABB operator*(const mat3 &M, const AABB &B)
{

	AABB retval;

	vec2 TL = { B.position.x - B.extents.x, B.position.y + B.extents.y };
	vec2 TR = B.position + B.extents;
	vec2 BL = B.position - B.extents;
	vec2 BR = { TR.x, BL.y };

	TR = (M * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (M * vec3{ BL.x, BL.y, 1 }).xy;
	TL = (M * vec3{ TL.x, TL.y, 1 }).xy;
	BR = (M * vec3{ BR.x, BR.y, 1 }).xy;



	vec2 MinCorner = min(TR, min(BL, min(TL, BR)));
	vec2 MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (MaxCorner + MinCorner) / 2;
	retval.extents = (MaxCorner - MinCorner) / 2;

	return retval;



	//return AABB();
}

