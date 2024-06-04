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
        // positions // colors // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f

    };

    float points2[] = {
        // positions // colors // texture coords
        0.3f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.3f, -0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.3f, -0.3f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.3f, 0.3f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };


    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    Mesh mesh = Mesh(points, 4, indices, 6);
    Mesh mesh2 = Mesh(points2, 4, indices, 6);

    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");

    Texture texture("res/Textures/brick.jpg");

    texture.slot = 3;
    texture.Bind();

    //Load Scene

    //Setting up vao
    VertexArray vao = VertexArray();

    Renderer square(mesh, program);

    Renderer square2(mesh2, program);


    int loc = program.GetUniform("InputColor");
    int texLoc = program.GetUniform("Tex");
    glUniform1i(texLoc, 3);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!(application.ShouldClose()))
    {
        application.ClearFrame();


        glUniform4f(loc, 0.2f, 0.5f, 0.1f, 1);
        square.Draw();


        glUniform4f(loc, 0.2f, 0.0f, 0.1f, 1);
        square2.Draw();

        application.SwapBuffer();
        application.PollEvents();
    }

    //Terminate

    //Errors::CheckError();

    application.Terminate();

    square.~Renderer();
    vao.~VertexArray();

    AtlasTerminate();
    return 0;
}