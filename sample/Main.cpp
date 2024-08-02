#include <iostream>

#include "../src/Atlas.h"

using namespace Atlas::CORE;
#ifdef ENABLE_ERROR_LOG
using namespace Atlas::CORE::Errors;
#endif
using namespace Atlas::Graphics;
using namespace glm;

int WinMain() {

    #ifdef ENABLE_ERROR_LOG
        ClearLogFile();
    #endif

    AtlasInnit();

    //Initiation
    Window application = Window(500,500, "Sample Square");
    application.EnableDepthTest();

    //application.SetFullScreen();

    Window::Main = &application;

    //Mesh Setup
    float points[] = {
        // positions // colors // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f

    };

    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    Mesh mesh = Mesh(points, 4, indices, 6);

    mat4x4 TransformMatrix(1.0f);

    TransformMatrix = translate(TransformMatrix, vec3(0.0f, 0.0f, -10.2f));
    TransformMatrix = scale(TransformMatrix, vec3(1.0f, 1.0f, 1.0f));


    //Camera Setup
    mat4x4 Projection(1.0f);
 
    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");

    Texture texture("res/Textures/brick.jpg");

    texture.slot = 3;
    texture.Bind();

    //Load Scene

    Renderer square(mesh, program);

    program.SetUniform("ourTexture", 3);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!(application.ShouldClose()))
    { 
        application.ClearFrame();
        application.ClearDepthBuffer();

        application.UpdateWindowSize();

        Projection = perspective(radians(45.0f), Window::Main->AspectRatio, 0.1f, 100.0f);
        program.SetUniform("Projection", Projection);

        TransformMatrix = rotate(TransformMatrix, radians(1.0f), vec3(0.0f, 1.0f, 0.0f));

        program.SetUniform("Transform", TransformMatrix);

        square.Draw();

        application.SwapBuffer();
        PollEvents();
    }

    //Terminate

    //Errors::CheckError();

    application.DestroyWindow();

    square.~Renderer();

    AtlasTerminate();
    return 0;
}