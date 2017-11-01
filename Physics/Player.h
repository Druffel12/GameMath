#pragma once

#include "Rigidbody.h"
#include "Collider.h"
#include "Sprite.h"
#include "Transform2.h"
#include "Controller.h"

class Player
{
public:
	Transform2 Transform2;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
};
class Wall
{
	Transform2 Transform2;
	Collider collider;
	Sprite sprite;
};

bool doCollision(Player &player, const Wall &wall);
bool doCollision(ball &ball, const Wall &wall);
bool doCollision(Player &player, const Wall &wall);