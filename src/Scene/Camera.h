#pragma once

#include "Transform.h"
#include "../Math.h"

using namespace Atlas::Scene;
using namespace glm;

namespace Atlas {
	namespace Scene {

		enum class CameraMode;

		class Camera{
		private:
			mat4x4 m_CameraViewMatrix;

		public:
			Transform transform;

			CameraMode Mode;

			float FOV;
			float NearClipPlane, FarClipPlane;

			static Camera Main;

			mat4x4 CameraMatrix;

			void UpdateMatrix();

			Camera();
			Camera(Transform t_Transform, CameraMode t_Mode,
				float t_FOV,
				float t_NearClip, float t_FarClip);
		};

		enum class CameraMode {
			Perspective,
			Orthographic
		};
	}
}