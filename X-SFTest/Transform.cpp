#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform()
{
	position = vec2 { 0,0 };
	dimension = vec2{ 1,1 };
	angle = 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransform() const
{
	return translate(position) * scale(dimension) * rotate(angle);
}

mat3 Transform::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}



}

void DrawMatrix(const mat3 &t, float drawing_scale)
{
	mat3 dummy = t;
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;


	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, RED);
	

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);


}