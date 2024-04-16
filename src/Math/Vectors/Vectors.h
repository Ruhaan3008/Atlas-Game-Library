#pragma once

namespace Atlas {
	namespace Math {

		struct Vector2 {
			double x, y;

			Vector2();
			Vector2(double t_X, double t_Y);

			void Negate();
			void Normalize();

			static double DistanceTo(const Vector2& From, const Vector2& To);
			static double Magnitude(const Vector2& t_Vector);
			static double DotProduct(const Vector2& a, const Vector2& b);

			//operator overloading
			Vector2 operator+(const Vector2& Vector);
			Vector2 operator-(const Vector2& Vector);
			Vector2 operator*(const double& Number);
			Vector2 operator/(const double& Number);

			Vector2 operator+=(const Vector2& Vector);
			Vector2 operator-=(const Vector2& Vector);
			Vector2 operator*=(const double& Number);
			Vector2 operator/=(const double& Number);
		};

		struct Vector3 {
			double x, y, z;

			Vector3();
			Vector3(double t_X, double t_Y, double t_Z);

			void Negate();
			void Normalize();

			static double DistanceTo(const Vector3& From, const Vector3& To);
			static double Magnitude(const Vector3& t_Vector);
			static double DotProduct(const Vector3& a, const Vector3& b);

			//Operator overloading
			Vector3 operator+(const Vector3& Vector);
			Vector3 operator-(const Vector3& Vector);
			Vector3 operator*(const double& Number);
			Vector3 operator/(const double& Number);

			Vector3 operator+=(const Vector3& Vector);
			Vector3 operator-=(const Vector3& Vector);
			Vector3 operator*=(const double& Number);
			Vector3 operator/=(const double& Number);

		};

		struct Vector4 {
			double x, y, z, w;
		};
	}
}