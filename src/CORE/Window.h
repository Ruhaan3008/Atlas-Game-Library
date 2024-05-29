#pragma once

namespace Atlas {
	namespace CORE {
		class Window {
		private:
			//Instance
			GLFWwindow* m_Window;

		public:

			int height;
			int width;

			//Clears the window
			void ClearFrame();

			//Swaps the Frame Buffer
			void SwapBuffer();

			//Update window size variable
			void UpdateWindowSize();

			//Gathers all the inputs
			void PollEvents();

			//Terminates this Window
			void Terminate();

			//Sets the window to full screen mode.
			void SetFullScreen();

			//Makes the window resizable if true is passes
			void Resizable(bool resizable);

			//Return true if a window close event is detected
			bool ShouldClose() { return glfwWindowShouldClose(m_Window); }
			
			//Constructor. Creates a new window.
			Window();
			Window(int height, int width, const char* windowName);
			//Destructor. Closes the window.
			~Window();
		
		};
	}
}