#include "Player.h"
#include "sfwdraw.h"
#include <random>
#include <iostream>
#include "sfwdraw.h"

void Player::update()
{
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
	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 20);
}