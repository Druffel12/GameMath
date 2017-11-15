#pragma once
#include "vec2.h"
#include  "sfwdraw.h"
#include "Transform.h"
#include "Sprites.h"
#include "Ball.h"
//include "collider.h"
class Player
{
public:
	Transform transform;
	Sprite sprite;
	//Collider collider
	char UP;
	char Down;
	char Right;
	char Left;

	Player(vec2 pos, char up, char down, char right,char left);

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

}

bool doCollision(Player2 P2, Ball Pong)
{

}

bool doCollision(Ball Pong, Wall Barrier)
{

}

bool doCollision(Player P1, Wall Barrier)
{

}

bool doCollision(Player2 P2, Wall Barrier)
{

}