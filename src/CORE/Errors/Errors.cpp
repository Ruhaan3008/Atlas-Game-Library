#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Error_struct.h"
#include "Log_Error.h"

using namespace Atlas::CORE::Errors;

void ClearError() {
	GLenum error = glGetError();
	while (glGetError() != GL_NO_ERROR);
}

void CheckOpenGlError() {

	GLenum error = glGetError();

	for (int i = 0; i <= 100; i++) {
		std::cout << "[OpenGL Error] " << error << ": " << glewGetErrorString(error) << '\n';

		error = glGetError();
		if (error == GL_NO_ERROR) {
			break;
		}
	}
}

bool LogError(const char* function, const char* file, int line) {

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


Error::Error(ErrorType t_E, ErrorSeverity t_S,
	string t_Description,
	string t_File, string t_Function, int t_Line) {
	e = t_E;
	s = t_S;
	ErrorCode = 0;
	Description = t_Description;
	file = t_File;
	function = t_Function;
	line = t_Line;

}

string Error::GetErrorMessage() {
	return "";
}

static string ErrorSeverityToString(ErrorSeverity s) {

	switch (s){

	case Debug:
		return "Debug";
		break;
		
	case Info:
		return "Info";
		break;
		
	case Warning:
		return "Warning";
		break;
		
	case Moderate:
		return "Moderate Error";
		break;
		
	case Fatal:
		return "Fatal Error";
		break;

	}

}

static string ErrorTypeToString(ErrorType e) {
	switch (e) {
	case Unknown:
		return "Unknown Error";
		break;

	case ShaderCompilation:
		return "Shader Compilation Error";
		break;

	case CORE:
		return "CORE Error";
		break;

	case Buffer:
		return "Buffer Error";
		break;

	case Math:
		return "Math Error";
		break;

	case OpenGL:
		return "OpenGL Error";
		break;

	case FileRead:
		return "File Read Error";
		break;

	case FileWrite:
		return "File Write Error";
		break;
	}
}