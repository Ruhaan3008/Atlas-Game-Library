#include "../Atlas.h"

#ifdef ENABLE_ERROR_LOG

using namespace Atlas::CORE::Errors;

#endif

void Atlas::CORE::AtlasInnit(){

    /* Initialize the library */
    if (!glfwInit()) {
#ifdef ENABLE_ERROR_LOG
        Error UnsuccessfulInnit = Error(ErrorType::OpenGL, ErrorSeverity::Fatal, (string)"Could not innitiate Atlas  Game Library.", ErrorOrigin);

        UnsuccessfulInnit.LogErrorToFile();

#endif
    };

    //GLFW verion
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    //Setting glfw mode to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef ENABLE_DEBUG_LOG

    Error DebugInfo(ErrorType::Core, ErrorSeverity::Info, (string) "Atlas Game Library was successfully Initiated.", ErrorOrigin);
    DebugInfo.LogErrorToFile();
#endif 

}

void Atlas::CORE::AtlasTerminate() {
    glfwTerminate();
}