#pragma once
#include "../Vectors/Vectors.h"


//Mathimatical constants
#define PI 3.14159265359
#define TAU 6.28318530718
#define E 2.71828182846

using namespace Atlas::Math;

namespace Atlas {
	namespace Math {
		//Degree and Radian Conversions
		template <typename T> T Deg2Rad(const T& deg);
		template <typename T> T Rad2Deg(const T& rad);

		//Max and Min Functions
		template <typename T> T Max(const T& a, const T& b);
		template <typename T> T Min(const T& a, const T& b);

		//Clamp
		template <typename T> T Clamp(const T& Min, const T& Max, const T& Number);

		//Rounding Functions
		template <typename T> T Floor(const T& Number);
		template <typename T> T Ceil(const T& Number);
		template <typename T> T Round(const T& Number);

		//Absoluete Value
		template <typename T> T Abs(const T& Number);

		//Vector Arrays to Float Arrays
		float* VectorToArray(const Vector2* vectorArray, const int arrayCount);
		float* VectorToArray(const Vector3* vectorArray, const int arrayCount);

		//Float Array to Vector Arrays
		Vector2* ArrarToVector2(const float* arr, const int arrayCount);
		Vector3* ArrarToVector3(const float* arr, const int arrayCount);
	}
}