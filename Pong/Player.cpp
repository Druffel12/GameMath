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

Player::Player(vec2 pos, char up, char down, char right, char left) 
{
	transform.position = pos;
	UP = up;
	Down = down;
	Right = right;
	Left = left;
}

//Player::~Player()
//{
//	//delete playerCollider.box;
//}

void Player::Draw()
{
	drawBox(transform.position, BoxHeigth, BoxWidth);
	//sprite.draw(transform);
}

void Player::Update(float dt)
{
	//playerBody.force = { 0,0 };

		if (sfw::getKey(UP))
		{
			playerBody.force.y += 500;
		}
		if (sfw::getKey(Left))
		{
			playerBody.force.x -= 500;
		}
		if (sfw::getKey(Down))
		{
			playerBody.force.y -= 500;
		}
		if (sfw::getKey(Right))
		{
			playerBody.force.x += 500;
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
		playerBody.integrate(transform, dt);
	
}

bool doCollision(Player &P1, Ball &Pong)
{
	// Check if objects are colliding and get info about the collision.
	// If the object is 2 pixels inside and to the right, we need to push it out that much.
	auto hitInfo = collides(P1.transform, P1.playerCollider, Pong.ballTransform, Pong.ballCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		//static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo);
		dynamic_resolution(P1.transform.position, P1.playerBody.velocity, P1.playerBody.mass, Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, hitInfo, 1);
		
		//Pong.speed += 1;
		P1.playerBody.mass += 1;
		
		return true;
		// dynamic_resolution(P1.transform.position, P1.playerBody, P1.playerBody.mass, Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, hitInfo, 1);
	}

	return false;
}

bool doCollision(Player2 P2, Ball Pong)
{
	auto hitInfo = collides(P2.Transform2, P2.Collider2, Pong.ballTransform, Pong.ballCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		dynamic_resolution(P2.Transform2.position, P2.player2Body.velocity, P2.player2Body.mass, Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, hitInfo, 1);
		//Pong.speed += 1;
		
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
	auto hitInfo = collides(Barrier.WallTransform, Barrier.WallCollider, P2.Transform2, Barrier.WallCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Barrier.WallTransform.position, Barrier.WallBody.velocity, hitInfo);
		return true;

	}

	return false;
}

bool doCollision(Player &P1, Player &P2)
{
	auto hitInfo = collides(P1.transform, P1.playerCollider, P2.transform, P2.playerCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		//static_resolution(P2.transform.position, P2.playerBody.velocity, hitInfo);
		dynamic_resolution(P1.transform.position, P1.playerBody.velocity, P1.playerBody.mass,
			P2.transform.position, P2.playerBody.velocity, P2.playerBody.mass, hitInfo, 3);
		return true;

	}

	return false;
}