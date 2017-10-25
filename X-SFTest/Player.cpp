#include "Player.h"
#include "sfwdraw.h"
#include <random>
#include <iostream>
#include <cmath>
#include "Transform.h"
#include "Enemy.h"

void Player::update()
{
	vec2 mousePos = vec2{ sfw::getMouseX(), sfw::getMouseY() };
	vec2 MouseDir = (norm(Loc.position - mousePos)) * 100;
	Loc.position = lerp(Loc.position, mousePos, sfw::getDeltaTime() / 1);
	float Degrees = VectorToAngle(MouseDir);

	Loc.angle = Degrees + 90;
	std::cout << Loc.angle << std::endl;

//	vec2 movement = { 0,0 };
//	float x = 1;
//	
//	float v1;
//	float v2;
//
//	v1 = rand() % 800 + 1;
//	v2 = rand() % 600 + 1;
//
//	if (sfw::getKey('Q'))
//	{
//		pos = { v1, v2 };
//		
//	}
//
//	//MACH 5
//	 if (sfw::getKey('E'))
//	{
//		x = 20;
//	}
//	 //Run
//	else if (sfw::getKey(' '))
//	{
//		x = 5;
//	}
//
//	else
//	{
//		x = 1;
//	}
//	if (sfw::getKey('W'))
//	{
//		movement.y += 1;
//	}
//	if (sfw::getKey('S'))
//	{
//		movement.y -= 1;
//	}
//	if (sfw::getKey('A'))
//	{
//		movement.x -= 1;
//	}
//	if (sfw::getKey('D'))
//	{
//		movement.x += 1;
//	}
//
//	pos += movement * x;
}

void Player::draw()
{
	
	//std::cout << "PX: " << Loc.position.x << "PY:" << Loc.position.y << std::endl;
	sfw::drawCircle(Loc.position.x, Loc.position.y, 20);
}
void Reticle::draw()
{
	vec2 mousePos = vec2{ sfw::getMouseX(), sfw::getMouseY() };
	vec2 LerpedPosition = lerp(Loc.position, mousePos, sfw::getDeltaTime());
	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 2);
}

bool Body::CheckCollision(Enemy e)
{
	if (dist(e.myT.pos, bodyLoc.position) < myRadius + e.Radius)
	{
		e.Enabled = false;
		return true;		//we are in collision
	}
	else
	return false;
}

void Body::update()
{
	//if (bodyLoc.e_parent != nullptr)
	//{
	//	//bodyLoc.position = lerp(bodyLoc.position, bodyLoc.e_parent->position, sfw::getDeltaTime() / 1);
	//	vec2 dir = norm(bodyLoc.e_parent->position - bodyLoc.position);
	//	float Degrees = VectorToAngle(dir);
	//	bodyLoc.angle = Degrees - 90;
	//}
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
	mat3 t = bodyLoc.getGlobalTransform();
	vec2 pos = t[2].xy;
	//::cout << "BX: " << pos.x << "BY:" << pos.y << std::endl;
	sfw::drawCircle(pos.x, pos.y, 10);
	DrawMatrix(t, 30);
}
