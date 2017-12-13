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
};