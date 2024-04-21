#pragma once
#include "Errors/Atlas_Errors.h"

namespace Atlas {
	namespace CORE {
		class Window {
		private:
			//Instance
			GLFWwindow* m_Window;

		public:

			int height;
			int width;

			//Returns the instance of the window
			GLFWwindow* GetInstance() { return m_Window; };

			//Updates Window
			void Update();
			//Terminates this Window
			void Terminate();

			//Sets the window to full screen mode.
			void SetFullScreen();

			void Resizable(bool resizable);
			
			//Constructor. Creates a new window.
			Window();
			Window(int height, int width, const char* windowName);
			//Destructor. Closes the window.
			~Window();
		
		};
	}
}