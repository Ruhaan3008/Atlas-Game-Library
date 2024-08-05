#include <iostream>

#include "../src/Atlas.h"

using namespace Atlas::CORE;
#ifdef ENABLE_ERROR_LOG
using namespace Atlas::CORE::Errors;
#endif
using namespace Atlas::Graphics;
using namespace Atlas::Scene;
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

    //Camera Setup
    Camera cam;
    mat4x4 Projection(1.0f);
 
    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");

    Texture texture("res/Textures/brick.jpg");

    texture.slot = 3;
    texture.Bind();

    //Load Scene

    Renderer square(mesh, program);

    Transform squareTransform(vec3(0.0f, 0.0f, -10.0f));
    squareTransform.Scale = vec3(1.0f, 1.0f, 1.0f);
    squareTransform.Rotation = vec3(1.0f, 0.0f, 0.0f);
    squareTransform.UpdateMatrix();


    program.SetUniform("ourTexture", 3);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!(application.ShouldClose()))
    { 
        application.ClearFrame();
        application.ClearDepthBuffer();

        application.UpdateWindowSize();

        Projection = perspective(radians(45.0f), Window::Main->AspectRatio, 0.1f, 100.0f);
        cam.UpdateMatrix();
        program.SetUniform("Projection", cam.CameraMatrix);

        squareTransform.Rotation.x += 1.0f;
        squareTransform.Rotation.y += 1.0f;
        squareTransform.Rotation.z += 1.0f;
        squareTransform.UpdateMatrix();

        program.SetUniform("Transform", squareTransform.Matrix);

        square.Draw();

        application.SwapBuffer();
        PollEvents();
    }

    //Terminate
    application.DestroyWindow();

    square.~Renderer();

    AtlasTerminate();
    return 0;
}