#pragma once
#include "Errors/Atlas_Errors.h"

namespace Atlas {
	namespace CORE {
		class Window {
		private:
			//Create new window
			void Start();

			//Instance
			GLFWwindow* m_window;

		public:

			//Returns the instance of the window
			GLFWwindow* GetInstance() { return m_window; };

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