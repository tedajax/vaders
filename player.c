#include "player.h"
#include "util.h"
#include "globals.h"
#include "input.h"

player_t player_make()
{
	player_t p;
	p.position = v2make(globals.window.width / 2 - 32, globals.window.height - 64);
	p.image = load_image("assets/tank.png");
	p.moveSpeed = 10.0f;
	return p;
}

void player_update(player_t *p)
{
	assert(p);

	if (input_get_key(SDLK_LEFT))
		p->position.x -= p->moveSpeed * globals.time.deltaf;

	if (input_get_key(SDLK_RIGHT))
		p->position.x += p->moveSpeed * globals.time.deltaf;
}

void player_draw(player_t *p)
{
	assert(p);

	apply_surface(p->position.x, p->position.y, p->image, globals.screen);
}
