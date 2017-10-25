#include "Enemy.h"
#include "sfwdraw.h"

//bool Enemy::CheckCollision()
//{
//	if(dist(DragonHead.pos,myT.Pos) < myRadius + DragonHead.Radius)
//	 Dragonhead.Enabled = false
//		return true		,we are in collision
//	else
//	 return false
//}

Enemy::Enemy()
{
}

bool Enemy::CheckCollision()
{
	return false;
}

void Enemy::update()
{
	//dir = norm(Player.pos - myT.Pos)
	//myT.Pos += dir * speed;
}

void Enemy::draw()
{
	mat3 t = myT.getGlobalTransform();
	vec2 pos = t[2].xy;
	sfw::drawCircle(pos.x, pos.y, 12);
	DrawMatrix(t, 30);
}

