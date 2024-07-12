#pragma once

namespace Atlas {
	namespace CORE {
		class Window {
		private:
			//Instance
			GLFWwindow* m_Window;
			unsigned int m_VertexArrayID;

			//Window initialization
			inline void Initiate(int t_Height, int t_Width, const char* windowName);

			//Screen coordinates reset after window resize
			static void FrameBufferSizeCallBack(GLFWwindow* window, int t_Width, int t_Height);

		public:

			int height;
			int width;

			//Clears the window
			void ClearFrame();

			//Clear Depth Buffer
			void ClearDepthBuffer();

			//Swaps the Frame Buffer
			void SwapBuffer();

			//Enable or disable glDepthTest
			void EnableDepthTest();
			void DisableDepthTest();

			//Update window size variable
			void UpdateWindowSize();

			//Terminates this Window
			void DestroyWindow();

			//Sets the window to full screen mode.
			void SetFullScreen();

			//Makes the window resizable if true is passes
			void Resizable(bool resizable);

			//Return true if a window close event is detected
			bool ShouldClose() { return glfwWindowShouldClose(m_Window); }
			
			//Constructor. Creates a new window.
			Window();
			Window(int t_Height, int t_Width, const char* windowName);
			//Destructor. Closes the window.
			~Window();
		
		};
	}
}