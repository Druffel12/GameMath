#include <iostream>
#include "sfwdraw.h"
#include "Player.h"
#include <time.h>
#include "Transform.h"

int main()
{
	sfw::initContext();

	Player Dragon;
	Dragon.Loc.position = { 400,300 };
	Dragon.Loc.dimension = { 1,1 };
	Dragon.Loc.angle = 0;

	Body part1;
	part1.bodyLoc.e_parent = &Dragon.Loc;
	part1.bodyLoc.position = { 0,-25 };
	part1.bodyLoc.dimension = { 1,1 };

	Body part2;
	part2.bodyLoc.e_parent = &part1.bodyLoc;
	part2.bodyLoc.position = { 0,-25 };
	part2.bodyLoc.dimension = { 1,1 };

	Body part3;
	part3.bodyLoc.e_parent = &part2.bodyLoc;
	part3.bodyLoc.position = { 0,-25 };
	part3.bodyLoc.dimension = { 1,1 };
	
	Body part4;
	part4.bodyLoc.e_parent = &part3.bodyLoc;
	part4.bodyLoc.position = { 0,-25 };
	part4.bodyLoc.dimension = { 1,1 };
	
	Body part5;
	part5.bodyLoc.e_parent = &part4.bodyLoc;
	part5.bodyLoc.position = { 0,-25 };
	part5.bodyLoc.dimension = { 1,1 };

	Body part6;
	part6.bodyLoc.e_parent = &part5.bodyLoc;
	part6.bodyLoc.position = { 0,-25 };
	part6.bodyLoc.dimension = { 1,1 };
	
	Body part7;
	part7.bodyLoc.e_parent = &part6.bodyLoc;
	part7.bodyLoc.position = { 0,-25 };
	part7.bodyLoc.dimension = { 1,1 };

	Body part8;
	part8.bodyLoc.e_parent = &part7.bodyLoc;
	part8.bodyLoc.position = { 0,-25 };
	part8.bodyLoc.dimension = { 1,1 };
	





	Reticle Aim;
	Aim.Loc.position = vec2{ 200,200 };

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
		Dragon.update();
		Dragon.draw();
		//part1.bodyLoc.angle += sfw::getDeltaTime() * 5;
		part1.update();
		part2.update();
		part3.update();
		part4.update();
		part5.update();
		part6.update();
		part7.update();
		part8.update();
		

		part1.draw();
		part2.draw();
		part3.draw();
		part4.draw();
		part5.draw();
		part6.draw();
		part7.draw();
		part8.draw();
		

		Aim.draw();
		float t = sfw::getTime();
		
		DrawMatrix(Dragon.Loc.getGlobalTransform(), 50);
		
		DrawMatrix(myBaby.getGlobalTransform(), 50);

		myTransform.angle += sfw::getDeltaTime() ;
		//myTransform.dimension = vec2{ sin(t) + 2, sinf(t) + 2 };

	//	myTransform.position += vec2{ 10, 10 };
	}

	sfw::termContext();


}
