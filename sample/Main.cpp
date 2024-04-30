#include <iostream>
#include "../src/Errors.h"
#include "../src/Atlas.h"
#include <GLFW/glfw3.h>

using namespace Atlas::CORE;
using namespace Atlas::CORE::Errors;
using namespace Atlas::Graphics;
using namespace Atlas::Graphics::Buffers;



int main() {
    //Initiation

    Window application = Window();

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

    RenderObject square(mesh, program);


    int loc = glGetUniformLocation(program.GetShaderID(), "InputColor");
    glUniform4f(loc, 0.2, 0.5, 0.1, 1);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(application.GetInstance()))
    {
        application.Update();
    }

    //Terminate

    //Errors::CheckError();

    application.Terminate();

    square.~RenderObject();
    vao.~VertexArray();

    glfwTerminate();
    return 0;
}