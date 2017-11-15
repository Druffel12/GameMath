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
	Player1.BoxHeigth = 10;
	Player1.transform.angle = 90;
	Player1.BoxWidth = 40; 
	Player1.sprite.dim = { 100, 20 };
	Player  Player2({ 700,300 }, 'I', 'K', 'L', 'J');
	Player2.BoxHeigth = 10;
	Player2.BoxWidth = 40;
	Player1.sprite.handle = sfw::loadTextureMap("Resources/American.png");
	Player2.sprite.handle = sfw::loadTextureMap("Resources/NKorea.png");


	while (sfw::stepContext())
	{
		Player1.Update();
		Player1.Draw();
		Player2.Update();
		Player2.Draw();
	
	}
	sfw::termContext();

	return 0;
}



