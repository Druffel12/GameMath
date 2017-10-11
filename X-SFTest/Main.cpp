#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include <time.h>

int main()
{
	sfw::initContext();

	srand(time(NULL));

	Player me;
	me.pos = { 400,300 };

	while (sfw::stepContext())
	{
		me.update();
		me.draw();
		std::cout << me.pos.x << me.pos.y << std::endl;
	}

	sfw::termContext();

}
