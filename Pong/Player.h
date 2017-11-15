#pragma once
#include "vec2.h"
#include  "sfwdraw.h"
#include "Transform.h"
#include "Sprites.h"
#include "Ball.h"
#include "Collider.h"
#include "Collision.h"
#include "Wall.h"
#include "Player2.h"

class Player
{
public:
	Transform transform;
	Sprite sprite;
	Collider playerCollider;
	Rigidbody playerBody;

	char UP;
	char Down;
	char Right;
	char Left;

	Player(vec2 pos, char up, char down, char right,char left);
	~Player();

	 float BoxWidth;
	 float BoxHeigth;

	void Draw();
	void  Update();

	
};

				//Wall				Ball
				// Ball				player
				// Player			Player
bool doCollision(Player P1, Ball Pong)
{
	// Check if objects are colliding and get info about the collision.
	// If the object is 2 pixels inside and to the right, we need to push it out that much.
	auto hitInfo = collides(P1.transform, P1.playerCollider, Pong.ballTransform, Pong.ballCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo);
		return true;
		// dynamic_resolution(P1.transform.position, P1.playerBody, P1.playerBody.mass, Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, hitInfo, 1);
	}

	return false;
}

bool doCollision(Player2 P2, Ball Pong)
{
	auto hitInfo = collides(P2.Player2Transform, P2.player2Collider, Pong.ballTransform, Pong.ballCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo);
		return true;
		
	}

	return false;
}

bool doCollision(Ball Pong, Wall Barrier)
{
	auto hitInfo = collides(Barrier.WallTransform, Barrier.WallCollider, Pong.ballTransform, Pong.ballCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo);
		return true;

	}

	return false;
}

bool doCollision(Player P1, Wall Barrier)
{
	auto hitInfo = collides(Barrier.WallTransform, Barrier.WallCollider, P1.transform, P1.playerCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Barrier.WallTransform.position, Barrier.WallBody.velocity, hitInfo);
		return true;

	}

	return false;
}

bool doCollision(Player2 P2, Wall Barrier)
{
	auto hitInfo = collides(Barrier.WallTransform, Barrier.WallCollider, P2.Player2Transform, Barrier.WallCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Barrier.WallTransform.position, Barrier.WallBody.velocity, hitInfo);
		return true;

	}

	return false;
}