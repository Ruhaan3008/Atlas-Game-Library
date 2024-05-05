#include "../Atlas.h"


void Atlas::CORE::AtlasInnit(){

    /* Initialize the library */
    glfwInit();

    //GLFW verion
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    //Setting glfw mode to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Atlas::CORE::TerminateGLFW() {
    glfwTerminate();
}