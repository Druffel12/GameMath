#include "Objects.h"

void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}
 
void drawLine(float BLX = 0, float BLY = 5, float BRX = 800, float BRY = 5)
{
	sfw::drawLine(BLX, BLY, BRX, BRY)
}

