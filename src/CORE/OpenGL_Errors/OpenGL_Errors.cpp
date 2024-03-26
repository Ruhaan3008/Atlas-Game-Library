#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../../Atlas.h"

void Atlas::CORE::OpenGL_Errors::ClearError() {
	GLenum error = glGetError();
	while (glGetError() != GL_NO_ERROR);
}

void Atlas::CORE::OpenGL_Errors::CheckError() {

	GLenum error = glGetError();

	for (int i = 0; i <= 100; i++) {
		std::cout << "[OpenGL Error] " << error << ": " << glewGetErrorString(error) << '\n';

		error = glGetError();
		if (error == GL_NO_ERROR) {
			break;
		}
	}
}

bool Atlas::CORE::OpenGL_Errors::LogError(const char* function, const char* file, int line) {

	GLenum error = glGetError();

	if (error == GL_NO_ERROR) {
		return true;
	}

	std::cout << "[OpenGL Error] " << error
		<< ": " << glewGetErrorString(error) << '\n'
		<< "	" << function << '\n'
		<< "	" << file << " " << " " << line
		<< '\n';

	return false;
}