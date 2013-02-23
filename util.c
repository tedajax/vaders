#include "util.h"

SDL_Surface *load_image(const char* filename)
{
	if (!filename) return NULL;

	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;
	loadedImage = IMG_Load(filename);

	if (loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
	}

	return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	if (source == NULL || destination == NULL)
		return;

	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, NULL, destination, &offset);
}

vec2 v2make(float x, float y)
{
	vec2 v; v.x = x; v.y = y;
	return v;
}

vec2 v2add(vec2 v1, vec2 v2)
{
	return v2make(v1.x + v2.x, v1.y + v2.y);
}

vec2 v2sub(vec2 v1, vec2 v2)
{
	return v2make(v1.x - v2.x, v1.y - v2.y);
}

vec2 v2mul(vec2 v1, vec2 v2)
{
	return v2make(v1.x * v2.x, v1.y * v2.y);
}

vec2 v2div(vec2 v1, vec2 v2)
{
	return v2make(v1.x / v2.x, v1.y / v2.y);
}

vec2 v2scale(vec2 vec, float scalar)
{
	return v2make(vec.x * scalar, vec.y * scalar);
}

float v2mag(vec2 vec)
{
	return sqrtf(SQR(vec.x) + SQR(vec.y));
}

vec2 v2norm(vec2 vec)
{
	float mag = v2mag(vec);
	assert(mag != 0);
	return v2make(vec.x / mag, vec.y / mag);
}

vec2 v2perp(vec2 vec)
{
	return v2make(-vec.y, vec.x);
}

vec2 v2neg(vec2 vec)
{
	return v2make(-vec.x, -vec.y);
}

point pointmake(int x, int y)
{
	point p; p.x = x; p.y = y;
	return p;
}

point point_from_vec2(vec2 vec)
{
	point p; p.x = (int)vec.x; p.y = (int)vec.y;
	return p;
}

