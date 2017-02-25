#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "bone.h"
#include "window.h"

int main(int argc, char **argv) {
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);

	Window window;
	window.mainloop();

	SDL_Quit();
	return 0;
}