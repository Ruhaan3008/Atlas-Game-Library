#include "Camera.h"
#include "../CORE/Window.h"

using namespace Atlas::CORE;


Atlas::Scene::Camera Atlas::Scene::Camera::Main;

void Atlas::Scene::Camera::UpdateMatrix() {
	transform.Scale = vec3(1.0f, 1.0f, 1.0f);
	transform.UpdateInverseMatrix();

	if (Mode == CameraMode::Perspective) {
		m_CameraViewMatrix = perspective(radians(FOV), 
			Window::Main->AspectRatio,
			NearClipPlane, FarClipPlane);
	}
	else {
		m_CameraViewMatrix = ortho( 0.0f, (float) Window::Main->width,
			0.0f,(float) Window::Main->height);
	}
	
	CameraMatrix = transform.InverseMatrix * m_CameraViewMatrix;
}

Atlas::Scene::Camera::Camera() :
	transform(),
	CameraMatrix(mat4x4(1.0f)), m_CameraViewMatrix(mat4x4(1.0f)),
	Mode(CameraMode::Perspective),
	FOV(45.0f), NearClipPlane(0.1f), FarClipPlane(100.0f) {}

Atlas::Scene::Camera::Camera(Transform t_Transform, CameraMode t_Mode, 
	float t_FOV, float t_NearClip, float t_FarClip) :
	transform(t_Transform), Mode(t_Mode),
	CameraMatrix(mat4x4(1.0f)), m_CameraViewMatrix(mat4x4(1.0f)),
	FOV(t_FOV),
	NearClipPlane(t_NearClip), FarClipPlane(t_FarClip) {}
