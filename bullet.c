#include <SDL/SDL.h>
#include "globals.h"
#include "util.h"
#include "bullet.h"

const float BULLET_DESTROY_HEIGHT = -5.0f;

void bullet_update(bullet_t *self)
{
	assert(self);
	self->position = v2add(self->position, v2scale(self->velocity, globals.time.deltaf));

	if (self->position.y <= BULLET_DESTROY_HEIGHT) {
		self->destroy = true;
	}
}

void bullet_draw(bullet_t *self)
{
	assert(self && self->image);
	apply_surface(self->position.x, self->position.y, self->image, globals.screen);
}

bool bullet_add(bullet_t *self)
{
	int index = 0;
	assert(self);

	index = bullet_next_index();
	if (index < 0) {
		return false;
	}

	bullets[index] = self;

	return true;
}

void bullet_remove(int index)
{
	assert(index >= 0 && index < MAX_BULLETS);

	if (bullets[index]) {
		free(bullets[index]);
		bullets[index] = NULL;

		stack_push(&freeIndices, (void *)&index);
	}
}

int bullet_next_index()
{
	int result;

	if (stack_size(&freeIndices) > 0) {
		void *dest = malloc(sizeof(int));
		stack_pop(&freeIndices, dest);
		result = *((int *)dest);
		free(dest);
	} else {
		result = -1;
	}

	return result;
}

void bullets_init()
{
	bullets = (bullet_t **)malloc(MAX_BULLETS * sizeof(bullet_t *));
	stack_init(&freeIndices, MAX_BULLETS, sizeof(int), NULL);

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets[i] = NULL;
		stack_push(&freeIndices, (void *)&i);
	}	
}

void bullets_update()
{
	int i;

	for (i = 0; i < MAX_BULLETS; ++i) {
		if (bullets[i]) {
			bullet_update(bullets[i]);
		}
	}

	for (i = 0; i < MAX_BULLETS; ++i) {
		if (bullets[i] && bullets[i]->destroy) {
			bullet_remove(i);
		}
	}
}

void bullets_draw()
{
	for (int i = 0; i < MAX_BULLETS; ++i) {
		if (bullets[i]) {
			bullet_draw(bullets[i]);
		}
	}
}

void bullets_cleanup()
{
	for (int i = 0; i < MAX_BULLETS; ++i) {
		if (bullets[i]) {
			free(bullets[i]);
			bullets[i] = NULL;
		}
	}

	free(bullets);
}
