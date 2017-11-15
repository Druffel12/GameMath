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
