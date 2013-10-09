vaders
======

SDL space invaders

Build and Run
=============
OSX:
	brew install SDL SDL_image SDL_gfx
	make
	./vaders

Linux:
	Prop something like
	<package manager of choice> <install command from PM of choice> SDL SDL_image SDL_gfx
	make
	./vaders
	
Windows:
	We use some C99 stuff so you gotta use MinGW
	Download SDL, figure out how to link with MinGW
	Look at make file, figure out what the command line should be
