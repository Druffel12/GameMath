#pragma once
#include "vec2.h"
#include "Transform.h"

class Player
{
public:
	Transform Loc;

	void update();
	void draw();
};