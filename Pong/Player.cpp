#include "Player.h"


void PlayerDraw()
{
	sfw::drawLine(bottomLeftX, bottomLeftY,
		topRightX, bottomLeftY);

	//left

	sfw::drawLine(bottomLeftX, bottomLeftY,
		bottomLeftX, topRightY);

	//top
	sfw::drawLine(bottomLeftX, topRightY,
		topRightX, topRightY);

	//right
	sfw::drawLine(topRightX, topRightY,
		topRightX, bottomLeftY);


}
class Player
{
public:
	void Move()
	{
		if (sfw::getKey('W'))
		{
			++y;
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
	}
};