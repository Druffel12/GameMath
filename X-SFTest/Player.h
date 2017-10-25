#pragma once
#include "vec2.h"
#include "Transform.h"
#include "mat3.h"
class Enemy;
class Player
{
public:
	Transform Loc;

	void update();
	void draw();
};

class Body
{
public:
	Transform bodyLoc;
	bool CheckCollision(Enemy e);
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


