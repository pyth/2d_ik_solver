#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <iostream>

#include <SDL2/SDL.h>

#include "chain.h"

class Window {
	bool running;
	bool new_target;
	int active_bone;
	SDL_Window *window;
	Chain *chain;
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	Vector2d target;
	SDL_Renderer *renderer;

	Window();
	~Window();

	void draw();
	void move_to_target();
	void mainloop();
};

#endif