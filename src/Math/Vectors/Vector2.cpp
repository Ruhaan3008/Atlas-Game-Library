#include "../../Atlas.h"

using namespace Atlas::Math;

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(double t_X, double t_Y) {
	x = t_X;
	y = t_Y;
}

double Vector2::DistanceTo(const Vector2& From, const Vector2& To) {
	double x = From.x - To.x;
	double y = From.y - To.y;

	x *= x;
	y *= y;

	double Distance = sqrt(x + y);

	return Distance;

}

double Vector2::Magnitude(const Vector2& t_Vector) {
	double x = t_Vector.x;
	double y = t_Vector.y;

	x *= x;
	y *= y;

	double Magnitude = sqrt(x + y);

	return Magnitude;
}

double Vector2::DotProduct(const Vector2& a, const Vector2& b) {
	return (a.x * b.x) + (a.y * b.y);
}

void Vector2::Negate() {
	x *= -1;
	y *= -1;
}

void Vector2::Normalize() {
	double mangnitude = Vector2::Magnitude(*this);
	mangnitude = 1 / mangnitude;
	*this = (*this) * mangnitude;

}

Vector2 Vector2::operator+(const Vector2& a) {
	return Vector2(a.x + this->x,a .y + this->y);

}

Vector2 Vector2::operator-(const Vector2& a) {
	return Vector2(this->x - a.x,this->y - a.y);

}

Vector2 Vector2::operator*(const double& Number) {
	return Vector2(this->x * Number,this->y * Number);
}

Vector2 Vector2::operator/(const double& Number) {
	return Vector2(this->x / Number, this->y / Number);
}

Vector2 Vector2::operator+=(const Vector2& a) {
	return Vector2(a.x + this->x,a .y + this->y);

}

Vector2 Vector2::operator-=(const Vector2& a) {
	return Vector2(this->x - a.x,this->y - a.y);

}

Vector2 Vector2::operator*=(const double& Number) {
	return Vector2(this->x * Number,this->y * Number);
}

Vector2 Vector2::operator/=(const double& Number) {
	return Vector2(this->x / Number, this->y / Number);
}