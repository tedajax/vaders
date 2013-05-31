#ifndef _VADERS_COLLIDER_H_
#define _VADERS_COLLIDER_H_

#include "util.h"

typedef struct 
{
	rect bounds;
	int tag;
	bool
} collider_t;

void collider_init(collider_t *self);


#endif