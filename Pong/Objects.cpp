#include "Objects.h"

void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}
struct circle
{
	vec2 position;
	float radius;
};