#ifndef _VADERS_PLAYER_H_
#define _VADERS_PLAYER_H_

#include <SDL/SDL.h>
#include "globals.h"
#include "util.h"

typedef struct 
{
	vec2 position;
	SDL_Surface *image;
	float moveSpeed;
} player_t;

player_t player_make();
void player_update(player_t *p);
void player_draw(player_t *p);

#endif