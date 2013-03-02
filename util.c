#include "util.h"

SDL_Surface *load_image(const char* filename)
{
	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;

	if (!filename) return NULL;
		
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
	SDL_Rect offset;

	if (source == NULL || destination == NULL)
		return;

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

rect rect_make(int x, int y, int width, int height)
{
	rect newrect = {x, y, width, height};
	return newrect;
}

rect rect_copy(rect *other)
{
	rect newrect = {other->x, other->y, other->w, other->h};
	return newrect;
}

int rect_left(rect *r)
{
	return r->x;
}

int rect_right(rect *r)
{
	return r->x + r->w;
}

int rect_top(rect *r)
{
	return r->y;
}

int rect_bottom(rect *r)
{
	return r->y + r->h;
}

bool rect_in_rect(rect *r1, rect *r2)
{
	
}

bool rect_in_circle(rect *r, circle *c)
{

}

circle circle_make(int x, int y, int radius)
{
	circle newcirc = {x, y, radius};
	return newcirc;
}

circle circle_copy(circle *other)
{
	circle newcirc = {other->x, other->y, other->r};
	return newcirc;
}

bool circle_in_rect(rect *r, circle *c)
{

}

bool circle_in_circle(circle *c1, circle *c2)
{
	
}
