#include <iostream>

#include "../src/Atlas.h"

using namespace Atlas::CORE;
#ifdef ENABLE_ERROR_LOG
using namespace Atlas::CORE::Errors;
#endif
using namespace Atlas::Graphics;
using namespace Atlas::Graphics::Buffers;



int WinMain() {

#ifdef ENABLE_ERROR_LOG
    ClearLogFile();
#endif

    AtlasInnit();

    //Initiation
    Window application = Window(500,500, "Sample Square");

    //application.SetFullScreen();

    //Mesh data
    float points[] = {
        -0.5, -0.5f, //0
        0.5f, -0.5f, //1
        0.5f, 0.5f,  //2
        -0.5f, 0.5f  //3

    };
    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    Mesh mesh = Mesh(points, 8, indices, 6);

    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");

    //Load Scene

    //Setting up vao
    VertexArray vao = VertexArray();

    Renderer square(mesh, program);


    int loc = program.GetUniform("InputColor");
    glUniform4f(loc, 0.2f, 0.5f, 0.1f, 1);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!(application.ShouldClose()))
    {
        application.Update();
    }

    //Terminate

    //Errors::CheckError();

    application.Terminate();

    square.~Renderer();
    vao.~VertexArray();

    AtlasTerminate();
    return 0;
}