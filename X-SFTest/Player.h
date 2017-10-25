#pragma once
#include "vec2.h"
#include "Transform.h"
#include "mat3.h"
#include "Enemy.h"
//class Enemy;
class Player
{
public:
	Player();
	Transform Loc;

	void update();
	void draw();
};

class Body
{
public:
	Transform bodyLoc;
	bool CheckCollision(Enemy Dragonborn);
	void update();
	void draw();
};

class Reticle
{
public:
	Transform Loc;

	void update();
	void draw();
};


