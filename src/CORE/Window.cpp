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

void Window::Update() {
    //Update screen size
    glfwGetWindowSize(m_Window, &(this->height), &(this->width));

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

    /* Swap front and back buffers */
    glfwSwapBuffers(this->m_Window);


    /* Poll for and process events */
    glfwPollEvents();
}

void Window::Terminate() {
    glfwDestroyWindow(this->m_Window);
}

Window::Window() {

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    this->height = 480;
    this->width = 640;

    /* Create a windowed mode window and its OpenGL context */
    m_Window = glfwCreateWindow(640, 480, "Atlas", NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);

    //Initiate glew aka Modern OpenGL
    glewInit();

#ifdef ENABLE_DEBUG_LOG

    string message = "Running version: ";
    message += (string) (char*) glGetString(GL_VERSION);

    Error DebugMsg = Error(OpenGL, Info, message, ErrorOrigin);

    DebugMsg.LogErrorToFile();

#endif
}
Window::Window(int height, int width, const char* windowName){
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    this->height = height;
    this->width = width;

    /* Create a windowed mode window and its OpenGL context */
    m_Window = glfwCreateWindow(width, height, windowName, NULL, NULL);

    if (!m_Window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);

    //Initiate glew aka Modern OpenGL
    glewInit();

#ifdef ENABLE_DEBUG_LOG

    string message = "Running version: ";
    message += (string)(char*)glGetString(GL_VERSION);

    Error DebugMsg = Error(OpenGL, Info, message, ErrorOrigin);

    DebugMsg.LogErrorToFile();

#endif

}
Window::~Window() {
    Window::Terminate();
}