#include <SDL/SDL.h>
#include "globals.h"
#include "util.h"
#include "bullet.h"

void bullet_update(bullet_t *bullet)
{
	assert(bullet);

	bullet->position = v2add(bullet->position, v2scale(bullet->velocity, globals.time.deltaf));
}

void bullet_draw(bullet_t *bullet)
{
	assert(bullet && bullet->image);

	apply_surface(bullet->position.x, bullet->position.y, bullet->image, globals.screen);
}

void init_bullets()
{
	int i;
	for (i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i] = NULL;
		freeBullets[i] = i;
	}	

	freeBulletsHead = 0;
}

bool add_bullet(bullet_t *bullet)
{
	int index = 0;

	assert(bullet);

	index = get_next_bullet_index();
	if (index < 0)
		return false;

	bullets[index] = bullet;

	return true;
}

void remove_bullet(int index)
{
	assert(index >= 0 && index < MAX_BULLETS);

	if (bullets[index])
	{
		bullets[index] = NULL;

		if (freeBulletsHead > 0)
		{
			freeBullets[--freeBulletsHead] = index;
		}
	}
}

int get_next_bullet_index()
{
	int result;

	if (freeBulletsHead < MAX_BULLETS)
	{
		result = freeBullets[freeBulletsHead++];
	}
	else
	{
		result = -1;
	}

	return result;
}

void bullets_update()
{
	int i;

	for (i = 0; i < MAX_BULLETS; i++)
	{
		bullet_update(bullets[i]);
	}

	for (i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i]->destroy)
			remove_bullet(i);
	}
}

void bullets_draw()
{
	int i;

	for (i = 0; i < MAX_BULLETS; i++)
	{
		bullet_draw(bullets[i]);
	}
}
