#include "bone.h"

Bone::Bone(unsigned int r, unsigned int g, unsigned int b, int parent_index) {
	this->root.setZero();
	this->color = Vector4i(r, g, b, 255);
	this->parent_index = parent_index;

	s.setConstant(1);
	r = 0.f;
	t.setZero();
	scale.setIdentity();
	rot.setIdentity();
	transl.setIdentity();
	offset.setIdentity();
	trafo.setIdentity();
}

Bone::~Bone() {
}

void Bone::set_offset(Vector2d offset) {
	this->offset(0, 2) = offset.x();
	this->offset(1, 2) = offset.y();
}

void Bone::set_scale(Vector2d scale) {
	s = scale;

	this->scale(0, 0) = scale.x();
	this->scale(1, 1) = scale.y();
}

void Bone::set_rot(double rot) {
	r = rot;

	this->rot(0, 0) = cos(rot);
	this->rot(1, 0) = sin(rot);
	this->rot(0, 1) = -sin(rot);
	this->rot(1, 1) = cos(rot);
}

void Bone::set_transl(Vector2d transl) {
	t = transl;

	this->transl(0, 2) = transl.x();
	this->transl(1, 2) = transl.y();
}

void Bone::increse_scale(Vector2d scale) {
	s += scale;
	set_scale(s);
}

void Bone::increse_rot(double rot) {
	r += rot;
	set_rot(r);
}

void Bone::increse_transl(Vector2d transl) {
	t += transl;
	set_transl(t);
}
