#pragma once
#include "Transform.h"
#include "Player.h"
class Enemy
{
public:
	Enemy();
	Enemy(Player d);
	bool Enabled;
	vec2 dir;
	Transform myT;
	Player dragon;
	float radius;
	float speed;
	bool CheckCollision();
	void update();
	void draw();
};