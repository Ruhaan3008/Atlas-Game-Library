#pragma once

namespace Atlas {
	namespace Math {

		struct Vector2 {
			float x, y;

			Vector2();
			Vector2(float t_X, float t_Y);

			//Function peformed with two vectors;
			static Vector2 Add(const Vector2* a,const Vector2* b);
			static Vector2 Multiply(float a, const Vector2* b);
			static float DotProduct(const Vector2* a,const Vector2* b);

			//Operation performed on one instance of vector
			void Negate();
			void Normalize();

			static float DistanceTo(const Vector2* From, const Vector2* To);
			static float Magnitude(const Vector2* t_Vector);
		};

		struct Vector3 {
			float x, y, z;

			Vector3();
			Vector3(float t_X, float t_Y, float t_Z);

		};

		struct Vector4 {
			float x, y, z, w;
		};
	}
}