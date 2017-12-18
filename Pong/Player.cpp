#include "Player.h"


void drawVec(vec2 a, vec2 b, unsigned color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawBox(vec2 pos, float w, float h, unsigned color)
{
	vec2 TL = {pos.x - w, pos.y + h};
	vec2 TR = { pos.x + w, pos.y + h };
	vec2 BL = { pos.x - w, pos.y - h };
	vec2 BR = {pos.x + w, pos.y -h};

	drawVec(TL, TR, color);
	drawVec(TR, BR, color);
	drawVec(BR, BL , color);
	drawVec(BL, TL, color);

	
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
	drawBox(transform.position, playerCollider.box.extents.x, playerCollider.box.extents.y, color);
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
		playerBody.integrate(transform, dt);

		/*if (transform.position.y > 400)
		{
			transform.position.y = 400;
		}*/

	
}

bool doCollision(Player &P1, Ball &Pong)
{
	// Check if objects are colliding and get info about the collision.
	// If the object is 2 pixels inside and to the right, we need to push it out that much.
	auto hitInfo = collides(Pong.ballTransform, Pong.ballCollider , P1.transform, P1.playerCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		//hitInfo.handedness *= -1;
		//static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo);
		dynamic_resolution( Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, P1.transform.position, P1.playerBody.velocity, P1.playerBody.mass, hitInfo, 1.3);

		//Pong.speed += 1;
		
		return true;
		// dynamic_resolution(P1.transform.position, P1.playerBody, P1.playerBody.mass, Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, hitInfo, 1);
	}

	return false;
}

bool doCollision(Player2 &P2, Ball &Pong)
{
	auto hitInfo = collides(Pong.ballTransform, Pong.ballCollider, P2.Transform2, P2.Collider2);

	if (hitInfo.penetrationDepth > 0)
	{
		//hitInfo.handedness *= -1;
		dynamic_resolution( Pong.ballTransform.position, Pong.Pong.velocity, Pong.Pong.mass, P2.Transform2.position, P2.player2Body.velocity, P2.player2Body.mass, hitInfo, 1.3);
		//Pong.speed += 1;
		
		return true;

	}

	return false;
}

bool doCollision(Ball &Pong, Wall &Barrier)
{
	auto hitInfo = collides(Pong.ballTransform, Pong.ballCollider, Barrier.WallTransform, Barrier.WallCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(Pong.ballTransform.position, Pong.Pong.velocity, hitInfo,.5);
		return true;

	}

	return false;
}

bool doCollision(Player &P1, const Wall &Barrier)
{
	auto hitInfo = collides( P1.transform, P1.playerCollider, Barrier.WallTransform, Barrier.WallCollider);

	if (hitInfo.penetrationDepth > 0)
	{
		
		static_resolution(P1.transform.position, P1.playerBody.velocity, hitInfo,1);
		/*dynamic_resolution(P1.transform.position, P1.playerBody.velocity, P1.playerBody.mass,
			Barrier.WallTransform.position, Barrier.WallBody.velocity, Barrier.WallBody.mass, hitInfo, 3);
		*/return true;

	}

	return false;
}

bool doCollision(Player2 &P2, const Wall &Barrier)
{
	auto hitInfo = collides(Barrier.WallTransform, Barrier.WallCollider, P2.Transform2, P2.Collider2);

	if (hitInfo.penetrationDepth > 0)
	{
		static_resolution(P2.Transform2.position, P2.player2Body.velocity, hitInfo,.5);
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
			P2.transform.position, P2.playerBody.velocity, P2.playerBody.mass, hitInfo, .5);
		return true;

	}

	return false;
}