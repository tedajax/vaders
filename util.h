/*
	Big file of various convenience functions and macros
*/

#ifndef _VADERS_UTIL_H_
#define _VADERS_UTIL_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <assert.h>

#define bool int
#define true 1
#define false 0

#define SQR(x) (x*x)

#define PI			3.14159265351f
#define PIOVER2 	1.57079632679f
#define TWOPIE 		6.28318530718f
#define RAD_TO_DEG 	57.29577951308f
#define DEG_TO_RAD 	0.01745329252f

typedef struct
{
	float x, y;
} vec2;

typedef struct
{
	int x, y;
} point;

SDL_Surface *load_image(const char* filename);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

vec2 v2make(float x, float y);
vec2 v2add(vec2 v1, vec2 v2);
vec2 v2sub(vec2 v1, vec2 v2);
vec2 v2mul(vec2 v1, vec2 v2);
vec2 v2div(vec2 v1, vec2 v2);
vec2 v2scale(vec2 vec, float scalar);
float v2mag(vec2 vec);
vec2 v2norm(vec2 vec);
vec2 v2perp(vec2 vec);
vec2 v2neg(vec2 vec);
point pointmake(int x, int y);
point point_from_vec2(vec2 vec);

float clampf(float val, float min, float max);

#endif
