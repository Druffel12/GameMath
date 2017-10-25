#include "Player.h"
#include "sfwdraw.h"
#include <random>
#include <iostream>
#include <cmath>
#include "Transform.h"
#include "Enemy.h"

Player::Player()
{
	enabled = true;
}

void Player::update()
{
	
	vec2 mousePos = vec2{ sfw::getMouseX(), sfw::getMouseY() };
	vec2 MouseDir = (norm(Loc.position - mousePos)) * 100;
	Loc.position = lerp(Loc.position, mousePos, sfw::getDeltaTime() / 1);
	float Degrees = VectorToAngle(MouseDir);

	Loc.angle = Degrees + 90;
	std::cout << Loc.angle << std::endl;

}

void Player::draw()
{
	if (enabled == true)
	{
		sfw::drawCircle(Loc.position.x, Loc.position.y, 20);
	}
	//std::cout << "PX: " << Loc.position.x << "PY:" << Loc.position.y << std::endl;
	
}
void Reticle::draw()
{
	vec2 mousePos = vec2{ sfw::getMouseX(), sfw::getMouseY() };
	vec2 LerpedPosition = lerp(Loc.position, mousePos, sfw::getDeltaTime());
	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 2);
}

bool Body::CheckCollision(Enemy &Dragonborn)
{
	mat3 t = bodyLoc.getGlobalTransform();
	vec2 pos = t[2].xy;
	if (dist(Dragonborn.myT.getGlobalTransform().c[2].xy, pos) < 10 + 12)
	{
		std::cout << "HIT ENEMY";
		Dragonborn.Enabled = false;
		return true;		//we are in collision
	}
	else
	return false;
}

void Body::update()
{
	if (Main.enabled == false)
	{
		enabled = false;
	}
	if (sfw::getKey('Q'))
	{
		bodyLoc.angle += 1;
	}
	if (sfw::getKey('E'))
	{
		bodyLoc.angle -= 1;
	}
	//Loc.position = lerp(Loc.position, Dragon, sfw::getDeltaTime() / 1);
	

}

void Body::draw()
{
	if(enabled == true)
	{ 
	mat3 t = bodyLoc.getGlobalTransform();
	vec2 pos = t[2].xy;
	//::cout << "BX: " << pos.x << "BY:" << pos.y << std::endl;
	sfw::drawCircle(pos.x, pos.y, 10);
	DrawMatrix(t, 30);
	}
}
