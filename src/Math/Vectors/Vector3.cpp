#include "../../Atlas.h"

using namespace Atlas::Math;

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;

}

Vector3::Vector3(float t_X, float t_Y, float t_Z) {
	x = t_X;
	y = t_Y;
	z = t_Z;

}

float Vector3::DistanceTo(const Vector3* From, const Vector3* To) {
	float x = (*From).x - (*To).x;
	float y = (*From).y - (*To).y;
	float z = (*From).z - (*To).z;

	x *= x;
	y *= y;
	z *= z;

	float Distance = sqrt(x + y + z);

	return Distance;

}

float Vector3::Magnitude(const Vector3* t_Vector) {
	float x = (*t_Vector).x;
	float y = (*t_Vector).y;
	float z = (*t_Vector).z;

	x *= x;
	y *= y;
	z *= z;

	float Magnitude = sqrt(x + y + z);

	return Magnitude;
}

Vector3 Vector3::Add(const Vector3* a, const Vector3* b) {
	float x = (*a).x + (*b).x;
	float y = (*a).y + (*b).y;
	float z = (*a).z + (*b).z;

	return Vector3(x, y, z);

}

Vector3 Vector3::Multiply(float a, const Vector3* b) {
	float x = a * (*b).x;
	float y = a * (*b).y;
	float z = a * (*b).z;

	return Vector3(x, y, z);
}

float Vector3::DotProduct(const Vector3* a, const Vector3* b) {
	return ((*a).x * (*b).x) + ((*a).y * (*b).y) + ((*a).z * (*b).z);
}

void Vector3::Negate() {
	x *= -1;
	y *= -1;
	z *= -1;
}

void Vector3::Normalize() {
	float mangnitude = Vector3::Magnitude(this);
	mangnitude = 1 / mangnitude;
	*this = Vector3::Multiply(mangnitude, this);

}