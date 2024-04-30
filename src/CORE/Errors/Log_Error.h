#pragma once
#include <vector>
#include <iostream>


using std::string;
using std::vector;

namespace Atlas {
	namespace CORE {
		namespace Errors{

			//Clears any pre-existing errors.
			void ClearError();

			//Prints any error that has occured;
			void CheckOpenGlError();

			//Return true if there is no error, returns false if there is an error.
			bool LogError();
		}
	}
}