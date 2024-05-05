#pragma once

#include "Window.h"


#ifdef ENABLE_ERROR_LOG

#include "Errors/Error_Struct.h"

#endif

namespace Atlas {
	namespace CORE {

		//Initiates Atlas
		void AtlasInnit();

		//Terminates GLFW
		void TerminateGLFW();
	}
}
