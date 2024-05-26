#pragma once

#ifdef ENABLE_ERROR_LOG

#include <iostream>
#include <fstream>

#include <string>

#include "Error_struct.h"
#include "Error_Definition.h"

using namespace Atlas::CORE::Errors;

static string Atlas::CORE::Errors::ErrorSeverityToString(ErrorSeverity s) {

	switch (s) {

	case ErrorSeverity::Debug:
		return "Debug";
		break;

	case ErrorSeverity::Info:
		return "Info";
		break;

	case ErrorSeverity::Warning:
		return "Warning";
		break;

	case ErrorSeverity::Moderate:
		return "Moderate Error";
		break;

	case ErrorSeverity::Fatal:
		return "Fatal Error";
		break;

	}

	return "Undocumented Error";

}

static string Atlas::CORE::Errors::ErrorTypeToString(ErrorType e) {
	switch (e) {
	case ErrorType::Unknown:
		return "Unknown";
		break;

	case ErrorType::ShaderCompilation:
		return "Shader Compilation";
		break;

	case ErrorType::Core:
		return "CORE";
		break;

	case ErrorType::Buffer:
		return "Buffer";
		break;

	case ErrorType::Math:
		return "Math";
		break;

	case ErrorType::OpenGL:
		return "OpenGL";
		break;

	case ErrorType::FileRead:
		return "File Read";
		break;

	case ErrorType::FileWrite:
		return "File Write";
		break;
	}

	return "Undocumented Error Type";
}

Atlas::CORE::Errors::Error::Error()
{
	Type = ErrorType::Unknown;
	Severity = ErrorSeverity::Info;
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
	ReturnString += Description + '\n';
	ReturnString += "\t" + function + "()" + '\n';
	ReturnString += '\t' + file + ", " + std::to_string(line) + '\n';
	return ReturnString;
}

void Atlas::CORE::Errors::Error::LogErrorToFile()
{
	std::fstream LogFile;

	LogFile.open(LOG_PATH, std::ios::app);

	if (LogFile.is_open())
	{
		LogFile << "Logged at ";
		LogFile << __TIME__;
		LogFile << '\n';
		LogFile << this->GetErrorMessage();
		LogFile << '\n';
		LogFile << '\n';

		LogFile.close();
	}
	else {
		std::cout << "Failed to open error log." << '\n';
		//TODO: Make exception handling for.
	}
}

void Atlas::CORE::Errors::Error::LogErrorToFile(string path)
{
	std::fstream LogFile;

	LogFile.open(path, std::ios::app);

	if (LogFile.is_open())
	{
		LogFile << "Logged at ";
		LogFile << __TIME__;
		LogFile << '\n';
		LogFile << this->GetErrorMessage();
		LogFile << '\n';
		LogFile << '\n';

		LogFile.close();
	}
	else {
		std::cout << "Failed to open error log." << '\n';
		//TODO: Make exception handling for this.
	}
}

void Atlas::CORE::Errors::Error::LogDebugInfoToFile()
{
	std::fstream LogFile;

	LogFile.open(DEBUG_PATH, std::ios::app);

	if (LogFile.is_open())
	{
		LogFile << "Logged at ";
		LogFile << __TIME__;
		LogFile << '\n';
		LogFile << this->GetErrorMessage();
		LogFile << '\n';
		LogFile << '\n';

		LogFile.close();
	}
	else {
		std::cout << "Failed to open error log." << '\n';
		//TODO: Make exception handling for.
	}
}

#endif