#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Wall
{
public:
	
	Transform WallTransform;
	Collider WallCollider;
	Rigidbody WallBody;
	void draw()
	{
		sfw::drawLine(WallTransform.position.x + (WallCollider.box.extents.x), WallTransform.position.y + (WallCollider.box.extents.y), WallTransform.position.x + (WallCollider.box.extents.x), WallTransform.position.y - (WallCollider.box.extents.y));//TR to BR
		sfw::drawLine(WallTransform.position.x + (WallCollider.box.extents.x), WallTransform.position.y - (WallCollider.box.extents.y), WallTransform.position.x - (WallCollider.box.extents.x), WallTransform.position.y - (WallCollider.box.extents.y));//BR to BL
		sfw::drawLine(WallTransform.position.x - (WallCollider.box.extents.x), WallTransform.position.y - (WallCollider.box.extents.y), WallTransform.position.x - (WallCollider.box.extents.x), WallTransform.position.y + (WallCollider.box.extents.y));//BL to TL
		sfw::drawLine(WallTransform.position.x - (WallCollider.box.extents.x), WallTransform.position.y + (WallCollider.box.extents.y), WallTransform.position.x + (WallCollider.box.extents.x), WallTransform.position.y + (WallCollider.box.extents.y));//TL to TR

																																																	  //Top Right Corner = position + extents

																																																	  //sfw::drawCircle(collider.position.x, collider.position.y, collider.radius, 12U, color);
	}
};