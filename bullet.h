#ifndef _VADERS_BULLET_H_
#define _VADERS_BULLET_H_

#include <SDL/SDL.h>
#include "globals.h"
#include "util.h"

#define MAX_BULLETS 200

typedef struct
{
	vec2 position;
	vec2 velocity;
	rect bounds;
	int sourceType;
	SDL_Surface *image;
	bool destroy;
} bullet_t;

void bullet_update(bullet_t *bullet);
void bullet_draw(bullet_t *bullet);

bullet_t *bullets[MAX_BULLETS];
int freeBullets[MAX_BULLETS];
int freeBulletsHead;

void init_bullets();
bool add_bullet(bullet_t *bullet);
void remove_bullet(int index);
int get_next_bullet_index();

void bullets_update();
void bullets_draw();

#endif