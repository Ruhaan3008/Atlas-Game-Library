#include <iostream>

#include "../src/Atlas.h"

using namespace Atlas::CORE;
#ifdef ENABLE_ERROR_LOG
using namespace Atlas::CORE::Errors;
#endif
using namespace Atlas::Graphics;
using namespace Atlas::Math;
using namespace Atlas::Math::glm;



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

    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    Matrix4 TransformMatrix(1.0f);

    TransformMatrix = glm::translate(TransformMatrix, Vector3(0.5f, 0.5f, 0.0f));
    TransformMatrix = glm::rotate(TransformMatrix, glm::radians(75.0f), Vector3(0.0f, 0.5f, 0.5f));
    TransformMatrix = glm::scale(TransformMatrix, Vector3(0.5f, 0.5f, 0.5f));

    Mesh mesh = Mesh(points, 4, indices, 6);

    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");

    Texture texture("res/Textures/brick.jpg");

    texture.slot = 3;
    texture.Bind();

    //Load Scene

    Renderer square(mesh, program);


    int loc = program.GetUniform("Transform");
    int texLoc = program.GetUniform("Tex");
    glUniform1i(texLoc, 3);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!(application.ShouldClose()))
    {
        application.ClearFrame();
        application.ClearDepthBuffer();


        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(TransformMatrix));
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