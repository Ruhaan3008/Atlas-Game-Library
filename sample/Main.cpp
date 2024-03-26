#include <iostream>
#include "../src/Atlas.h"
#include <GLFW/glfw3.h>

using namespace Atlas::CORE;
using namespace Atlas::Graphics;
using namespace Atlas::Graphics::Buffers;


int main() {
    //Initiation

    Window application = Window();

    //application.SetFullScreen();

    //Mesh data
    float points[] = {
        -0.5f, -0.5f, //0
        0.5f, -0.5f, //1
        0.5f, 0.5f,  //2
        -0.5f, 0.5f  //3

    };
    unsigned int indices[] = {
        0,1,2,
        2,3,0
    };

    //Load Scene

    //Setting up vao
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //setting up vertex buffer
    VertexBuffer vbo(points, sizeof(points));
    vbo.Bind();

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    

    IndexBuffer ibo(indices, sizeof(indices));
    ibo.Bind();

    Shader program = Shader("res/Shaders/BasicVertexShader.glsl", "res/Shaders/BasicFragmentShader.glsl");
    glUseProgram(program.GetShaderID());

    int loc = glGetUniformLocation(program.GetShaderID(), "InputColor");
    glUniform4f(loc, 1, 1, 1, 1);

    //Main Game Loop

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(application.window))
    {
        application.Update();
    }

    //Terminate

    OpenGL_Errors::CheckError();

    application.Terminate();

    glDeleteBuffers(1, &vao);
    vbo.Unbind();
    ibo.Unbind();
    vbo.~VertexBuffer();
    ibo.~IndexBuffer();

    glfwTerminate();
    return 0;
}