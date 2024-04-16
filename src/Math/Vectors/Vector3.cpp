#include "../../Atlas.h"

using namespace Atlas::Math;

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;

}

Vector3::Vector3(double t_X, double t_Y, double t_Z) {
	x = t_X;
	y = t_Y;
	z = t_Z;

}

double Vector3::DistanceTo(const Vector3& From, const Vector3& To) {
	double x = From.x - To.x;
	double y = From.y - To.y;
	double z = From.z - To.z;

	x *= x;
	y *= y;
	z *= z;

	double Distance = sqrt(x + y + z);

	return Distance;

}

double Vector3::Magnitude(const Vector3& t_Vector) {
	double x = t_Vector.x;
	double y = t_Vector.y;
	double z = t_Vector.z;

	x *= x;
	y *= y;
	z *= z;

	double Magnitude = sqrt(x + y + z);

	return Magnitude;
}

Vector3 Vector3::operator+(const Vector3& Vector) {

	return Vector3(this->x + Vector.x, this->y + Vector.y, this->z + Vector.z);

}

Vector3 Vector3::operator-(const Vector3& Vector) {

	return Vector3(this->x - Vector.x, this->y - Vector.y, this->z - Vector.z);

}

Vector3 Vector3::operator*(const double& Number) {

	return Vector3(this->x * Number, this->y * Number, this->z * Number);

}

Vector3 Vector3::operator/(const double& Number) {

	return Vector3(this->x / Number, this->y / Number, this->z / Number);

}

Vector3 Vector3::operator+=(const Vector3& Vector) {

	return Vector3(this->x + Vector.x, this->y + Vector.y, this->z + Vector.z);

}

Vector3 Vector3::operator-=(const Vector3& Vector) {

	return Vector3(this->x - Vector.x, this->y - Vector.y, this->z - Vector.z);

}

Vector3 Vector3::operator*=(const double& Number) {

	return Vector3(this->x * Number, this->y * Number, this->z * Number);

}

Vector3 Vector3::operator/=(const double& Number) {

	return Vector3(this->x / Number, this->y / Number, this->z / Number);

}

double Vector3::DotProduct(const Vector3& a, const Vector3& b) {
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

void Vector3::Negate() {
	x *= -1;
	y *= -1;
	z *= -1;
}

void Vector3::Normalize() {
	double mangnitude = Vector3::Magnitude(*this);
	mangnitude = 1 / mangnitude;
	*this *= mangnitude;

}