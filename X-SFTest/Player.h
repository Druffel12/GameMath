#pragma once
#include "vec2.h"
#include "Transform.h"
#include "mat3.h"

class Enemy;


class Player
{
public:
	Player();
	Transform Loc;
	bool enabled;
	void update();
	void draw();
};

class Body
{
public:
	Player Main;
	bool enabled = true;
	Transform bodyLoc;
	bool CheckCollision(Enemy &Dragonborn);
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


