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
	vec2 velocity;
	vec2 force;
	unsigned color;

	char UP;
	char Down;
	char Right;
	char Left;

	Player(vec2 pos, char up, char down, char right,char left);

	 float BoxWidth;
	 float BoxHeigth;

	void Draw();
	void Update(float dt);

};
struct tester
{
	AABB collider;

	unsigned int up;
	unsigned int down;
	unsigned int left;
	unsigned int right;

	unsigned color;

	void update()
	{
		if (sfw::getKey(up))
		{
			collider.position.y += 100;
		}
		if (sfw::getKey(down))
		{
			collider.position.y -= 100;
		}
		if (sfw::getKey(left))
		{
			collider.position.x -= 100;
		}
		if (sfw::getKey(right))
		{
			collider.position.x += 100;
		}
	}

	void draw()
	{
		sfw::drawLine(collider.position.x + (collider.extents.x), collider.position.y + (collider.extents.y), collider.position.x + (collider.extents.x), collider.position.y - (collider.extents.y));//TR to BR
		sfw::drawLine(collider.position.x + (collider.extents.x), collider.position.y - (collider.extents.y), collider.position.x - (collider.extents.x), collider.position.y - (collider.extents.y));//BR to BL
		sfw::drawLine(collider.position.x - (collider.extents.x), collider.position.y - (collider.extents.y), collider.position.x - (collider.extents.x), collider.position.y + (collider.extents.y));//BL to TL
		sfw::drawLine(collider.position.x - (collider.extents.x), collider.position.y + (collider.extents.y), collider.position.x + (collider.extents.x), collider.position.y + (collider.extents.y));//TL to TR

																																																	  //Top Right Corner = position + extents

																																																	  //sfw::drawCircle(collider.position.x, collider.position.y, collider.radius, 12U, color);
	}
};

				//Wall				Ball
				// Ball				player
				// Player			Player
bool doCollision(Player &P1, Ball &Pong);
bool doCollision(Player2 &P2, Ball &Pong);
bool doCollision(Ball &Pong, Wall &Barrier);
bool doCollision(Player &P1, const Wall &Barrier);
bool doCollision(Player2 &P2, Wall &Barrier);
bool doCollision(Player &P1, Player &P2);