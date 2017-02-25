#ifndef __CHAIN_H__
#define __CHAIN_H__

#include <vector>

#include <SDL2/SDL.h>

#include "bone.h"

class Chain {
	SDL_Renderer *renderer;
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	std::vector<Bone *> bones;
	Vector2d effector;

	Chain(SDL_Renderer *renderer);
	~Chain();

	void add_link(Bone *bone);
	void move_to_target(Vector2d& target);
	void update();
	void draw();
};

#endif