#pragma once
#include "Transform.h"
#include "Player.h"
class Enemy
{
	vec2 dir;
	Transform myT;
	float radius;
	float speed;
	Player DragonHead;
	bool CheckCollision();
	void update();
	void draw();
};