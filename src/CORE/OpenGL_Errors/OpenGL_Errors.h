#pragma once

#define ASSERT(x) if (!(x)) __debugbreak();
//Stop and code execution if there is any OpenGL error and print any error that occured.
#define ErrCall(x) Atlas::CORE::OpenGL_Errors::ClearError();\
	x;\
	ASSERT(Atlas::CORE::OpenGL_Errors::LogError(#x, __FILE__, __LINE__))


namespace Atlas {
	namespace CORE {
		namespace OpenGL_Errors {

			//Clears any pre-existing errors.
			void ClearError();

			//Prints any error that has occured;
			void CheckError();

			//Return true if there is no error, returns false if there is an error.
			bool LogError(const char* function, const char* file, int line);

		}
	}
}