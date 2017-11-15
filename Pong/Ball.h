#pragma once
#include "Objects.h"
#include "Sprites.h"
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Ball
{
public:
	Transform ballTransform;
	Sprite ballSprite;
	Collider ballCollider;
	Rigidbody Pong;
	Ball();
	~Ball();
	
	
};


void drawCircle(const circle &C);
