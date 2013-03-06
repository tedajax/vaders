#include "player.h"
#include "util.h"
#include "globals.h"
#include "input.h"
#include "bullet.h"
#include "images.h"
#include <math.h>

player_t player_make()
{
	player_t p;
	p.position = v2make(globals.window.width / 2 - 32, globals.window.height - 64);
	p.image = get_image("tank");
	p.moveSpeed = 500.0f;
	return p;
}

void player_update(player_t *p)
{
	assert(p);

	if (input_get_key(SDLK_LEFT))
		p->position.x -= p->moveSpeed * globals.time.deltaf;

	if (input_get_key(SDLK_RIGHT))
		p->position.x += p->moveSpeed * globals.time.deltaf;

	if (input_get_key_down(SDLK_z))
	{
		bullet_t bullet;
		bullet.position = p->position;
		bullet.velocity = v2make(0.0f, -100.0f);
		bullet.sourceType = 0;
		bullet.image = get_image("bullet");
		bullet.destroy = false;

		add_bullet(&bullet);
	}

	p->position.x = clampf(p->position.x, 0, globals.window.width - 64);
}

void player_draw(player_t *p)
{
	assert(p);

	apply_surface(p->position.x, p->position.y, p->image, globals.screen);
}

