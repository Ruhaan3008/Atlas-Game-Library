#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../Atlas.h"

using namespace Atlas::CORE;

void Window::Start() {

    GLFWwindow*& win = this->window;

    /* Initialize the library */
    glfwInit();

    //GLFW verion
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    //Setting glfw mode to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    win = glfwCreateWindow(640, 480, "Atlas", NULL, NULL);
    if (!win)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(win);

    //Initiate glew aka Modern OpenGL
    glewInit();

    std::cout << glGetString(GL_VERSION) << '\n';

}

void Window::SetFullScreen() {

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();

    //Gets the setting of the monitor
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    //sets window to full screen
    glfwSetWindowMonitor(this->window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
}

void Window::Update() {

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    /* Swap front and back buffers */
    glfwSwapBuffers(this->window);

    /* Poll for and process events */
    glfwPollEvents();
}

void Window::Terminate() {
    glfwDestroyWindow(this->window);
}

void Atlas::CORE::TerminateGLFW() {
    glfwTerminate();
}

Window::Window() {
    Start();
}
Window::~Window() {
    Window::Terminate();
}