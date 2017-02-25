#ifndef __BONE_H__
#define __BONE_H__

#include <Eigen/Dense>

using namespace Eigen;

class Bone {
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	Vector2d s;
	double r;
	Vector2d t;

	Matrix3d scale;
	Matrix3d rot;
	Matrix3d transl;

	Matrix3d trafo;
	Matrix3d offset;
	int parent_index;

	Vector4i color;
	Vector2d root;
	Vector2d end;

	Bone(unsigned int r, unsigned int g, unsigned int b, int parent_index = -1);
	~Bone();

	void set_offset(Vector2d offset);
	void set_scale(Vector2d scale);
	void set_rot(double rot);
	void set_transl(Vector2d transl);

	void increse_scale(Vector2d scale);
	void increse_rot(double rot);
	void increse_transl(Vector2d transl);
};

#endif
