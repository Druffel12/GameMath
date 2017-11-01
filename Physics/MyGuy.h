#pragma once
#include "Transform2.h"
#include "vec2.h"
class myGuy
{
public:
	Transform2 myTrans;
	float Speed;
	float turnSpeed;

	myGuy(float speed, float rotSpeed, vec2 pos, vec2 dim, float anglez);


	void update(/*const mat3 & t*/);
	void draw(const mat3 & t);
};