#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include <time.h>
#include "Transform.h"

int main()
{
	sfw::initContext();

	Player Dragon;

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = 0;

	Transform myBaby;
	myBaby.position = vec2{ 100,100 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;

	while (sfw::stepContext())
	{
		Dragon.draw();
		float t = sfw::getTime();
		
		DrawMatrix(myTransform.getGlobalTransform(), 50);
		
		DrawMatrix(myBaby.getGlobalTransform(), 50);

		myTransform.angle += sfw::getDeltaTime() ;
		//myTransform.dimension = vec2{ sin(t) + 2, sinf(t) + 2 };

	//	myTransform.position += vec2{ 10, 10 };
	}

	sfw::termContext();


}
