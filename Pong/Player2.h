#pragma once
#include "vec2.h"
#include  "sfwdraw.h"
#include "Transform.h"
#include "Sprites.h"
#include "Ball.h"
#include "Collider.h"
#include "Collision.h"

class Player2
{
public:
	Transform Player2Transform;
	Sprite sprite2;
	Collider player2Collider;
	Rigidbody player2Body;

	int score = 0;

	float bottomLeftX;
	float bottomLeftY;

	float topRightX;
	float topRightY;
};