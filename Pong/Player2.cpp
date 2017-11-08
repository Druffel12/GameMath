#include "Player2.h"


void Player2Draw()
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
class Player2
{
public:
	void Move()
	{
		if (sfw::getKey('I'))
		{
			++y;
		}
		if (sfw::getKey('J'))
		{
			--x;
		}
		if (sfw::getKey('K'))
		{
			--y;
		}
		if (sfw::getKey('L'))
		{
			++x;
		}
		//Rotate Left
		if (sfw::getKey('U'))
		{

		}
		//Rotate Right
		if (sfw::getKey('O'))
		{

		}
	}

};