
#include "sfwdraw.h"
#include "Player.h"
#include "DrawShapes.h"


int main()
{
	sfw::initContext();


	Player player;

	player.sprite = sfw::loadTextureMap("../resources/Terry.jpg");
	player.Transform2.dimension = vec2{ 48, 48 };
	player.Transform2.position = vec2{ 400,300 };
	player.collider.box.extents = { .5,.5 };

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		player.controller.poll(player.rigidbody, player.Transform2);

		player.rigidbody.integrate(player.Transform2, dt);

		player.sprite.draw(player.Transform2);


		drawAABB(player.collider.getGlobalBox(player.Transform2), MAGENTA);
	}

	sfw::termContext();
}