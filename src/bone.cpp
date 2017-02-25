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

void Bone::set_offset(int x, int y) {
	this->offset(0, 2) = x;
	this->offset(1, 2) = y;
}

void Bone::set_scale(int x, int y) {
	s << x, y;

	this->scale(0, 0) = x;
	this->scale(1, 1) = y;
}

void Bone::set_rot(double rot) {
	r = rot;

	this->rot(0, 0) = cos(rot);
	this->rot(1, 0) = sin(rot);
	this->rot(0, 1) = -sin(rot);
	this->rot(1, 1) = cos(rot);
}

void Bone::set_transl(int x, int y) {
	t << x, y;

	this->transl(0, 2) = x;
	this->transl(1, 2) = y;
}

void Bone::increse_scale(int x, int y) {
	s.x() += x;
	s.y() += y;
	set_scale(s.x(), s.y());
}

void Bone::increse_rot(double rot) {
	r += rot;
	set_rot(r);
}

void Bone::increse_transl(int x, int y) {
	t.x() += x;
	t.y() += y;
	set_transl(t.x(), t.y());
}
