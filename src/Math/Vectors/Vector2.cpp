#include "../../Atlas.h"

using namespace Atlas::Math;

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float t_X, float t_Y) {
	x = t_X;
	y = t_Y;
}

float Vector2::DistanceTo(const Vector2* From, const Vector2* To) {
	float x = (*From).x - (*To).x;
	float y = (*From).y - (*To).y;

	x *= x;
	y *= y;

	float Distance = sqrt(x + y);

	return Distance;

}

float Vector2::Magnitude(const Vector2* t_Vector) {
	float x = (*t_Vector).x;
	float y = (*t_Vector).y;

	x *= x;
	y *= y;

	float Magnitude = sqrt(x + y);

	return Magnitude;
}

Vector2 Vector2::Add(const Vector2* a, const Vector2* b) {
	float x = (*a).x + (*b).x;
	float y = (*a).y + (*b).y;

	return Vector2(x, y);

}

Vector2 Vector2::Multiply(float a, const Vector2* b) {
	float x = a * (*b).x;
	float y = a * (*b).y;

	return Vector2(x, y);
}

float Vector2::DotProduct(const Vector2* a, const Vector2* b) {
	return ((*a).x * (*b).x) + ((*a).y * (*b).y);
}

void Vector2::Negate() {
	x *= -1;
	y *= -1;
}

void Vector2::Normalize() {
	float mangnitude = Vector2::Magnitude(this);
	mangnitude = 1 / mangnitude;
	*this = Vector2::Multiply(mangnitude, this);

}
