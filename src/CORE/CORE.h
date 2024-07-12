#pragma once

#include "Window.h"


#ifdef ENABLE_ERROR_LOG

#include "Errors/Error_Struct.h"
#include "Errors/Error_Definition.h"
#include "Errors/Log_File.h"

#endif

namespace Atlas {
	namespace CORE {

		//Initiates Atlas
		void AtlasInnit();

		//Gather all inputs
		void PollEvents();

		//Terminates GLFW
		void AtlasTerminate();
	}
}
