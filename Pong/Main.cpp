#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include "Player2.h"
#include "Objects.h"
#include "Sprites.h"




int main()
{
	sfw::initContext();

	Player  Player1({100,300},'W','S','D','A');
	Player1.playerCollider.box.extents = { 10,40 };
	Player1.BoxHeigth = 10;
	Player1.BoxWidth = 40; 
	Player1.sprite.dim = { 100, 20 };
	Player  Player2({ 700,300 }, 'I', 'K', 'L', 'J');
	Player2.playerCollider.box.extents = { 10,40 }; 
	Player2.BoxHeigth = 10;
	Player2.BoxWidth = 40;
	Player1.sprite.handle = sfw::loadTextureMap("Resources/American.png");
	Player2.sprite.handle = sfw::loadTextureMap("Resources/NKorea.png");
	Wall;

	/*tester p1;
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
	p2.right = 'L';*/

	Ball ball;

	while (sfw::stepContext())
	{
		Player1.Update(sfw::getDeltaTime());
		Player1.Draw();
		Player2.Update(sfw::getDeltaTime());
		Player2.Draw();
		doCollision(Player1, Player2);
		/*p1.update();
		p1.draw();
		doCollision(Player1, ball);
		p2.update();
		p2.draw();*/
	}
	sfw::termContext();

	return 0;
}



