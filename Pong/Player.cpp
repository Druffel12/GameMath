#include "Player.h"


void drawVec(vec2 a, vec2 b)
{
	sfw::drawLine(a.x, a.y, b.x, b.y);
}

void drawBox(vec2 pos, float w, float h)
{
	vec2 TL = {pos.x - w, pos.y + h};
	vec2 TR = { pos.x + w, pos.y + h };
	vec2 BL = { pos.x - w, pos.y - h };
	vec2 BR = {pos.x + w, pos.y -h};

	drawVec(TL, TR);
	drawVec(TR, BR);
	drawVec(BR, BL);
	drawVec(BL, TL);
}

Player::Player(vec2 pos, char up, char down, char right, char left) : playerCollider(new AABB())
{
	transform.position = pos;
	UP = up;
	Down = down;
	Right = right;
	Left = left;
}

Player::~Player()
{
	delete playerCollider.box;
}

void Player::Draw()
{
	drawBox(transform.position, BoxHeigth, BoxWidth);
	sprite.draw(transform);
}

void Player::Update()
{
		if (sfw::getKey(UP))
		{
			transform.position.y += 3.5;
		}
		if (sfw::getKey(Left))
		{
			transform.position.x -= 3.5;
		}
		if (sfw::getKey(Down))
		{
			 transform.position.y -= 3.5;
		}
		if (sfw::getKey(Right))
		{
			 transform.position.x += 3.5;
		}
		//rotate left
		if (sfw::getKey('Q'))
		{
			transform.angle += 1;
		}
		//rotate right
		if (sfw::getKey('E'))
		{
			transform.angle -= 1;	
		}
	
}

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