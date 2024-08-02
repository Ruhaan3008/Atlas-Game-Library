#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../Atlas.h"

#ifdef ENABLE_DEBUG_LOG
#include "Errors/Error_Definition.h"
#include "Errors/Error_struct.h"

using namespace Atlas::CORE::Errors;

#endif

using namespace Atlas::CORE;

Atlas::CORE::Window* Atlas::CORE::Window::Main;

void Window::SetFullScreen() {

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();

    //Gets the setting of the monitor
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    //sets window to full screen
    glfwSetWindowMonitor(this->m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
}

void Window::Resizable(bool resizable){
    if (resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        return;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void Window::ClearFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::ClearDepthBuffer() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Window::EnableDepthTest(){
    glEnable(GL_DEPTH_TEST);

}

void Window::DisableDepthTest() {
    glDisable(GL_DEPTH_TEST);

}

void Window::SwapBuffer() {
    glfwSwapBuffers(this->m_Window);
}

void Window::UpdateWindowSize() {
    glfwGetWindowSize(m_Window, &(this->height), &(this->width));
    this->AspectRatio = (float)height / (float)width;
}

void Window::FrameBufferSizeCallBack(GLFWwindow* window, int t_Width, int t_Height) {
    glViewport(0, 0, t_Width, t_Height);
}

void Window::DestroyWindow() {
    glfwDestroyWindow(this->m_Window);
}

void Window::Initiate(int t_Height, int t_Width, const char* windowName) {
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    this->height = t_Height;
    this->width = t_Width;

    this->AspectRatio = (float)t_Height / (float)t_Width;

    /* Create a windowed mode window and its OpenGL context */
    m_Window = glfwCreateWindow(t_Width, t_Height, windowName, NULL, NULL);

    if (!m_Window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);

    glfwSetFramebufferSizeCallback(m_Window, Window::FrameBufferSizeCallBack);

    //Initiate glew aka Modern OpenGL
    glewInit();

    glGenVertexArrays(1, &(this->m_VertexArrayID));
    glBindVertexArray(this->m_VertexArrayID);

    #ifdef ENABLE_DEBUG_LOG
    {
        string message = "Running version: ";
        message += (string)(char*)glGetString(GL_VERSION);

        Error DebugMsg = Error(ErrorType::OpenGL, ErrorSeverity::Info, message, ErrorOrigin);

        DebugMsg.LogErrorToFile();
    }
    #endif

}

Window::Window() {
    this->Initiate(420, 690, "Atlas");
}
Window::Window(int t_Height, int t_Width, const char* windowName){
    this->Initiate(t_Height, t_Width, windowName);
}
Window::~Window() {
    glDeleteVertexArrays(1, &(this->m_VertexArrayID));
    Window::DestroyWindow();
}