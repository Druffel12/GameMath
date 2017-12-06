#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include "Player2.h"
#include "Objects.h"
#include "Sprites.h"

struct tester
{
	circle collider;

	unsigned int up;
	unsigned int down;

	unsigned color;

	void update()
	{
		if (sfw::getKey(up))
		{
			collider.position.y += 10;
		}
		if (sfw::getKey(down))
		{
			collider.position.y -= 10;
		}
	}

	void draw()
	{
		sfw::drawCircle(collider.position.x, collider.position.y, collider.radius, 12U, color);
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
	p1.collider.position = { 200,200 };
	p1.collider.radius = 15;
	p1.up = 'W';
	p1.down = 'S';
	
	tester p2;
	p2.collider.position = { 210,200 };
	p2.collider.radius = 10;
	p2.up = 'I';
	p2.down = 'K';

	while (sfw::stepContext())
	{
		Player1.Update();
		Player1.Draw();
		Player2.Update();
		Player2.Draw();
	
		p1.update();
		p1.draw();

		p2.update();
		p2.draw();
	}
	sfw::termContext();

	return 0;
}



