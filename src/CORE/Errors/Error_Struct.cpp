#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Error_struct.h"
#include "Log_Error.h"

using namespace Atlas::CORE::Errors;

static string ErrorSeverityToString(ErrorSeverity s) {

	switch (s) {

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

	return "Undocumented Error";

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

	return "Undocumented Error Type";
}

Atlas::CORE::Errors::Error::Error()
{
	Type = Unknown;
	Severity = Info;
	ErrorCode = 0;
	Description = "";
	file = "";
	function = "";
	line = 0;
}

Error::Error(ErrorType t_E, ErrorSeverity t_S,
	string t_Description,
	string t_File, string t_Function, int t_Line) {

	Type = t_E;
	Severity = t_S;
	ErrorCode = 0;
	Description = t_Description;
	file = t_File;
	function = t_Function;
	line = t_Line;

}

string Error::GetErrorMessage() {

	string ErrorType = ErrorTypeToString(Type);
	string ErrorSeverity = ErrorSeverityToString(Severity);
	string ReturnString = "[" + ErrorType + "]";
	ReturnString += " " + ErrorSeverity + '\n';
	ReturnString += std::to_string(ErrorCode) + ": " + Description + '\n';
	ReturnString += function + " Function" + '\n';
	ReturnString += file + " " + std::to_string(line) +'\n';
	return ReturnString;
}