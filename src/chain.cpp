#include "chain.h"

Chain::Chain(SDL_Renderer *renderer) {
	this->renderer = renderer;
}

Chain::~Chain() {
	for(Bone *bone : bones) {
		delete bone;
	}
}

void Chain::add_link(Bone *bone) {
	bones.push_back(bone);
}

void Chain::move_to_target(Vector2d& target) {
	Vector2d de = 0.001f * (target - effector) / (target - effector).norm();
	MatrixXd mat(3, bones.size());
	for(unsigned int i = 0; i < bones.size(); i++) {
		Vector2d tmp = effector - bones[i]->root;
		mat.col(i) = Vector3d(Vector3d(0, 0, 1).cross(Vector3d(tmp.x(), tmp.y(), 1)));
	}
	
	MatrixXd inv = mat.transpose();
	VectorXd dt = inv * Vector3d(de.x(), de.y(), 0);
	for(unsigned int i = 0; i < bones.size(); i++) {
		//if(std::abs(bones[i]->r + dt[i] / 180.0 * M_PI) < M_PI / 2)
		bones[i]->increse_rot(dt[i] / 180.0 * M_PI);
	}
	update();
}

void Chain::update() {
	for(unsigned int i = 0; i < bones.size(); i++) {
		bones[i]->trafo = bones[i]->transl * bones[i]->rot * bones[i]->scale;
		if (bones[i]->parent_index >= 0) {
			Bone *parent = bones[bones[i]->parent_index];
			bones[i]->trafo = parent->trafo * parent->offset * bones[i]->trafo;
		}
		Vector3d tmp = bones[i]->trafo * Vector3d(0, 0, 1);
		bones[i]->root = Vector2d(tmp.x(), tmp.y());
		tmp = bones[i]->trafo * bones[i]->offset * Vector3d(0, 0, 1);
		bones[i]->end = Vector2d(tmp.x(), tmp.y());
		if(i == bones.size() - 1) {
			effector.x() = bones[i]->end.x();
			effector.y() = bones[i]->end.y();
		}
	}
}

void Chain::draw() {
	update();
	for(Bone *bone : bones) {
		SDL_SetRenderDrawColor(renderer, bone->color.x(), bone->color.y(), bone->color.z(), bone->color.w());
		SDL_RenderDrawLine(renderer, bone->root.x(), bone->root.y(), bone->end.x(), bone->end.y());
	}
}
