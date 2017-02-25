#include "window.h"

Window::Window() {
	running = true;
	new_target = false;
	active_bone = 0;
	window = SDL_CreateWindow("IK Solver", 100, 100, 1024, 768, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	chain = new Chain(renderer);

	Bone *bone1 = new Bone(255, 0, 0);
	bone1->set_rot(0.f);
	bone1->set_transl(Vector2d(250, 300));
	bone1->set_offset(Vector2d(200, 0));
	chain->add_link(bone1);

	Bone *bone2 = new Bone(0, 255, 0, 0);
	bone2->set_offset(Eigen::Vector2d(100, 0));
	chain->add_link(bone2);

	Bone *bone3 = new Bone(0, 0, 255, 1);
	bone3->set_offset(Eigen::Vector2d(50, 0));
	chain->add_link(bone3);

	Bone *bone4 = new Bone(255, 0, 255, 2);
	bone4->set_offset(Eigen::Vector2d(25, 0));
	chain->add_link(bone4);
}

Window::~Window() {
	delete chain;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::mainloop() {
	while(running) {
		SDL_Event e;
		if(SDL_PollEvent(&e)) {
			switch(e.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_1:
					active_bone = 0;
					break;
				case SDLK_2:
					active_bone = 1;
					break;
				case SDLK_3:
					active_bone = 2;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				target.x() = (float)e.button.x;
				target.y() = (float)e.button.y;
				new_target = true;
				break;
			case SDL_MOUSEWHEEL:
				chain->bones[active_bone]->increse_rot(e.wheel.y / 180.0 * M_PI);
				break;
			}
		}

		move_to_target();
		draw();

		SDL_RenderPresent(renderer);
		SDL_Delay(1);
	}
}

void Window::move_to_target() {
	if(new_target) {
		Eigen::Vector2d e_tmp = chain->effector;
		chain->move_to_target(target);
		if((e_tmp - chain->effector).norm() < 0.0001f || (chain->effector - target).norm() < 1)
			new_target = false;
	}
}

void Window::draw() {
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderClear(renderer);

	chain->draw();

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect;
	rect.x = target.x() - 3;
	rect.y = target.y() - 3;
	rect.w = 5;
	rect.h = 5;
	SDL_RenderFillRect(renderer, &rect);
}
