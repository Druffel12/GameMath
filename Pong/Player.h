#pragma once
#include "vec2.h"
#include  "sfwdraw.h"

class Player
{
public:
	void Move()
	{
	if (sfw::getKey('W'))
	{
		++y;
		updatedraw Player
	}
	if (sfw::getKey('A'))
	{
		--x;
	}
	if (sfw::getKey('S'))
	{
		--y;
	}
	if (sfw::getKey('D'))
	{
		++x;
	}
	//rotate left
	if (sfw::getKey('Q'))
	{

	}
	//rotate right
	if (sfw::getKey('E'))
	{

	}
};