#include "Enemy.h"
#include "sfwdraw.h"
#include "Player.h"


Enemy::Enemy()
{
	Enabled = false;
}

Enemy::Enemy(Player d)
{
	Enabled = false;
	dragon = d;
}

bool Enemy::CheckCollision()
{
	if (dist(dragon.Loc.position, myT.position) < 10 + 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::update()
{
	//dir = norm(Player.pos - myT.Pos)
	dir = norm(dragon.Loc.position - myT.position);
	myT.position += dir * 5;
	//myT.position += dir * 5;
}

void Enemy::draw()
{
	mat3 t = myT.getGlobalTransform();
	vec2 pos = t[2].xy;
	sfw::drawCircle(pos.x, pos.y, 12);
	DrawMatrix(t, 30);
}

