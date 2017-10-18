#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include <time.h>
#include "mat3.h"
#include "Transform.h"

int main()
{
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 1,1 };

	while (sfw::stepContext())
	{
		DrawMatrix(myTransform.getLocalTransform(), 40);
	}

	sfw::termContext();


}
