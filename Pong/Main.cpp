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
#include "Score.h"


int main()
{
		
	sfw::initContext();
	

	int fonthandle = sfw::loadTextureMap("fontmap.png", 16, 16);

	int score1 = 0;
	int score2 = 0;

	Player  Player1({100,300},'W','S','D','A');
	Player1.color = RED;
	Player1.playerCollider.box.extents = { 10,40 };
	Player1.BoxHeigth = 10;
	Player1.BoxWidth = 40; 
	Player1.sprite.dim = { 100, 20 };
	
	Player  Player2({ 700,300 }, 'I', 'K', 'L', 'J');
	Player2.color = GREEN;
	Player2.playerCollider.box.extents = { 10,40 }; 
	Player2.BoxHeigth = 10;
	Player2.BoxWidth = 40;
	//Player1.sprite.handle = sfw::loadTextureMap("Resources/American.png");
	//Player2.sprite.handle = sfw::loadTextureMap("Resources/NKorea.png");
	
	Wall Barrier;//upper
	Barrier.WallTransform.position = { 400, 580 };
	Barrier.WallCollider.box.extents = { 1000, 25 };
	Barrier.WallTransform.dimension = { 1, 1 };
	
	Wall Barrier2;//lower
	Barrier2.WallTransform.position = { 400, -25 };
	Barrier2.WallCollider.box.extents = { 1000, 25 };
	Barrier2.WallTransform.dimension = { 1, 1 };
	
	Wall Barrier3;//left
	Barrier3.WallTransform.position = { -25, 400 };
	Barrier3.WallCollider.box.extents = { 25, 800 };
	Barrier3.WallTransform.dimension = { 1, 1};

	Wall Barrier4;//right
	Barrier4.WallTransform.position = { 825, 400 };
	Barrier4.WallCollider.box.extents = { 25, 800 };
	Barrier4.WallTransform.dimension = { 1, 1};

	Wall walls[4] = {Barrier, Barrier2, Barrier3, Barrier4};

	Ball ball;
	ball.ballTransform.position = { 400, 300 };
	ball.ballCollider.box.extents = {10, 10};
	//ball.ballCollider.box.extents = { 50 , 50 };


	int Winner =0;

	while (sfw::stepContext())
	{

		if (Winner == 1)
		{
			sfw::drawString(fonthandle, "P1 Wins!!!", 0, 350, 80, 100);
		}
		else if (Winner == 2)
		{
			sfw::drawString(fonthandle, "P2 Wins!!!", 0, 350, 80, 100);
		}

		sfw::drawString(fonthandle, "Pong", 300, 590, 50, 40);
	//sfw::drawString(fonthandle, std::stoi(score1), 100, 590, 50, 40);



		float deltatime = sfw::getDeltaTime();
	
		sfw::drawLine(0, 555, 800, 555);
		for (int i = 0; i < 4; i++)
		{
			doCollision(Player1, walls[i]);
			doCollision(Player2, walls[i]);
		}
		//doCollision(Player1, barrier);

		char digits[2] = { 48 + score1,'\0' };
		char * test = digits;

		sfw::drawString(fonthandle, test, 100, 590, 50, 40);

		 digits[0] = 48 + score2;
		 test = digits;

		 sfw::drawString(fonthandle, test, 700, 590, 50, 40);

		Player1.Update(deltatime);
		Player1.Draw();
		Player2.Update(deltatime);
		Player2.Draw();
		ball.update(deltatime);
		ball.Draw();
//		std::cout << ball.ballCollider.cir.position.x << " " << ball.ballCollider.cir.position.x << std::endl;
		
		doCollision(ball, Barrier);
		doCollision(ball, Barrier2);
		Barrier.draw();
		//point detectiond
		if (doCollision(ball, Barrier3))
		{
			ball.ballTransform.position = { 400, 300 };
			ball.Pong.velocity = { 0,4000 };
			ball.Pong.acceleration = { 0, 0 };
			ball.Pong.angularAcceleration = 0;
				score2 += 1;
				if (score2 >= 7)
				{
					Winner = 2;
					score2 = 0;
				}
				else
				{
					Winner = 0;
				}
		}
		if (doCollision(ball, Barrier4))
		{
			ball.ballTransform.position = { 400, 300 };
			ball.Pong.velocity = { -10,-20 };
			ball.Pong.acceleration = { 0, 0 };
			ball.Pong.angularAcceleration = 0;
				score1 += 1;
				if (score1 >= 7)
				{
					Winner = 1;
					score1 = 0;
				}
				else
				{
					Winner = 0;
				}
		}

	
		//players vs walls
		
		//player vs player
		doCollision(Player1, Player2);
		doCollision(Player1, ball);
		doCollision(Player2, ball);

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



