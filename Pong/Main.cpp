/*TO DO:
1. make ball
2. score board
3. add title
4. make game reset
*/
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
	
	Wall Barrier;//upper
	Barrier.WallTransform.position = { 400, 580 };
	Barrier.WallCollider.box.extents = { 1000, 25 };
	Barrier.WallTransform.dimension = { 1000, 50 };
	
	Wall Barrier2;//lower
	Barrier2.WallTransform.position = { 400, -25 };
	Barrier2.WallCollider.box.extents = { 1000, 25 };
	Barrier2.WallTransform.dimension = { 1000, 50 };
	
	Wall Barrier3;//left
	Barrier3.WallTransform.position = { -25, 400 };
	Barrier3.WallCollider.box.extents = { 25, 800 };
	Barrier3.WallTransform.dimension = { 50, 800 };

	Wall Barrier4;//right
	Barrier4.WallTransform.position = { 825, 400 };
	Barrier4.WallCollider.box.extents = { 25, 800 };
	Barrier4.WallTransform.dimension = { 50, 800 };


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
	ball.ballTransform.position = { 400, 300 };
	ball.ballCollider.box.extents = { 50 , 50 };

	while (sfw::stepContext())
	{
		sfw::drawLine(0, 555, 800, 555);
		Player1.Update(sfw::getDeltaTime());
		Player1.Draw();
		Player2.Update(sfw::getDeltaTime());
		Player2.Draw();
		//point detection
		if (doCollision(ball, Barrier3))
		{
			//point player 2
			//reset the ball
		}
		if (doCollision(ball, Barrier4))
		{
			//point player 1
			//reset the ball
		}
		//players vs walls
		doCollision(Player1, Barrier);
		//player vs player
		doCollision(Player1, Player2);
		
		//reset score, player position and velocity, ball position and velocity
		
		/*p1.update();
		p1.draw();
		doCollision(Player1, ball);
		p2.update();
		p2.draw();*/
	}
	sfw::termContext();

	return 0;
}



