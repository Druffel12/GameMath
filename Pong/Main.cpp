#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include "Player2.h"
#include "Objects.h"
#include "Sprites.h"

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
			collider.position.y += 3.5;
		}
		if (sfw::getKey(down))
		{
			collider.position.y -= 3.5;
		}
		if (sfw::getKey(left))
		{
			collider.position.x -= 3.5;
		}
		if (sfw::getKey(right))
		{
			collider.position.x += 3.5;
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

int main()
{
	sfw::initContext();

	Player  Player1({100,300},'W','S','D','A');
	Player1.BoxHeigth = 10;
	Player1.transform.angle = 90;
	Player1.BoxWidth = 40; 
	Player1.sprite.dim = { 100, 20 };
	Player  Player2({ 700,300 }, 'I', 'K', 'L', 'J');
	Player2.BoxHeigth = 10;
	Player2.BoxWidth = 40;
	Player1.sprite.handle = sfw::loadTextureMap("Resources/American.png");
	Player2.sprite.handle = sfw::loadTextureMap("Resources/NKorea.png");

	tester p1;
	p1.collider.position = { 100,300 };
	p1.collider.extents = { 10,40 };
	p1.up = 'W';
	p1.down = 'S';
	p1.left = 'A';
	p1.right = 'D';
	
	tester p2;
	p2.collider.position = { 700,300 };
	p2.collider.extents = { 10,40 };
	p2.up = 'I';
	p2.down = 'K';
	p2.left = 'J';
	p2.right = 'L';

	Ball ball;

	while (sfw::stepContext())
	{
		Player1.Update();
		Player1.Draw();
		Player2.Update();
		Player2.Draw();
	
		p1.update();
		p1.draw();
		doCollision(Player1, ball);
		p2.update();
		p2.draw();
	}
	sfw::termContext();

	return 0;
}



