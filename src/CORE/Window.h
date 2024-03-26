#pragma once
#include "OpenGL_Errors/OpenGL_Errors.h"

namespace Atlas {
	namespace CORE {
		class Window {
		private:
			//Create new window
			void Start();

		public:
			//Instance
			GLFWwindow* window;

			//Updates Window
			void Update();
			//Terminates this Window
			void Terminate();

			//Sets the window to full screen mode.
			void SetFullScreen();
			
			//Constructor. Creates a new window.
			Window();
			//Destructor. Closes the window.
			~Window();
		
		};

		//Terminates GLFW
		void TerminateGLFW();
	}
}