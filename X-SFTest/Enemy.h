#pragma once
#include "Transform.h"
#include "Player.h"
class Enemy
{
public:
	Enemy();
	bool Enabled;
	vec2 dir;
	Transform myT;
	float radius;
	float speed;
	bool CheckCollision();
	void update();
	void draw();
};