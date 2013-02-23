#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include "util.h"
#include "globals.h"
#include "input.h"
#include "player.h"

player_t player;

bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;

	init_globals();

	SDL_SetVideoMode(globals.window.width,
					 globals.window.height, 
					 globals.window.bpp, 
					 SDL_SWSURFACE);

	globals.screen = SDL_GetVideoSurface();

	if (globals.screen == NULL)
		return false;

	SDL_WM_SetCaption("Vaders", NULL);

	input_init();

	return true;
}

void cleanup()
{
	input_cleanup();
	SDL_FreeSurface(globals.screen);
	SDL_Quit();
}

void update()
{
	player_update(&player);
}

void draw()
{
	player_draw(&player);
}

int main(int argc, char* argv[])
{
	if (init() == false)
		return EXIT_FAILURE;

	SDL_Event event;

	player = player_make();

	long flipTime = 0;

	while (globals.bRun)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				globals.bRun = false;
		}

		SDL_FillRect(globals.screen, NULL, SDL_MapRGB(globals.screen->format, 0, 0, 0));

		if (input_get_key_down(SDLK_ESCAPE))
			globals.bRun = false;

		update();
		draw();

		input_update();
		SDL_Flip(globals.screen);
	}

	cleanup();
	return EXIT_SUCCESS;
}
