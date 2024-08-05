#pragma once

#include "../Math.h"
using namespace glm;

namespace Atlas {
	namespace Scene {
		struct Transform {
			mat4x4 Matrix;
			mat4x4 InverseMatrix;

			vec3 Position;
			vec3 Rotation;
			vec3 Scale;

			static vec3 xAxis;
			static vec3 yAxis;
			static vec3 zAxis;

			void UpdateMatrix();
			void UpdateInverseMatrix();

			Transform(vec3 t_Position);
			Transform(vec3 t_Position, vec3 t_Rotation);
			Transform(vec3 t_Position, vec3 t_Rotation, vec3 t_Scale);
		};
	}
}