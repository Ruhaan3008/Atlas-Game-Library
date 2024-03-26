#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics;

unsigned int Shader::CreateComponentShader(GLenum type,string ShaderSource) {
	//compiles component shader
	unsigned int shader = glCreateShader(type);
	const char* src = ShaderSource.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);


	//handle errors in the source code

	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	//check if ther are any errors
	if (result == GL_FALSE) {
		//Creating the error message
		int lenght;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)malloc(lenght * sizeof(char));
		glGetShaderInfoLog(shader, lenght, &lenght, message);

		std::cout << "[Shader Compilation Error]: ";
		std::cout << message << '\n';
		std::cout << ShaderSource << '\n';
		std::cout << '\n';
		std::cout << '\n';

		free(message);
	}

	return shader;

}

string Shader::ReadShaderFile(string path) {

	std::ifstream file(path);

	if (!file.is_open()) {
		return "";
	}

	std::stringstream ss{};
	ss << file.rdbuf();
	file.close();

	return ss.str();
}

void Shader::CreateShader() {
	//vertex and fragment shader
	this->shader_id = glCreateProgram();
	//unsigned int vertexShader = Shader::CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	//unsigned int fragmentShader = Shader::CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	//attaches component shader to master shaders
	glAttachShader(this->shader_id, this->vertexShader);
	glAttachShader(this->shader_id, this->fragmentShader);

	//compile the master shader
	glLinkProgram(this->shader_id);

}

int Shader::GetUniform(char uniformName) {
	return glGetUniformLocation(this->shader_id, &uniformName);
}

Shader::Shader(string VertexShaderPath, string FragmentShaderPath) {
	this->vertexShaderPath = VertexShaderPath;
	this->fragmentShaderPath = FragmentShaderPath;

	this->vertexShaderSource = ReadShaderFile(this->vertexShaderPath);
	this->fragmentShaderSource = ReadShaderFile(this->fragmentShaderPath);

	this->vertexShader = CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	this->fragmentShader = CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	CreateShader();

}

Shader::Shader() {
	string VertexShaderPath = "";
	string FragmentShaderPath =
		"#version 450 core\n"
		"precision highp float;\n"
		"out vec4 color;\n"
		"void main() {\n"
		"color = vec4(1,1,1,1);\n"
		"}; \n";
	this->vertexShaderPath = VertexShaderPath;
	this->fragmentShaderPath = FragmentShaderPath;

	this->vertexShaderSource = ReadShaderFile(this->vertexShaderPath);
	this->fragmentShaderSource = ReadShaderFile(this->fragmentShaderPath);

	this->vertexShader = CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	this->fragmentShader = CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	CreateShader();

}

Shader::~Shader() {
	glDeleteShader(this->vertexShader);
	glDeleteShader(this->fragmentShader);
	glDeleteShader(this->shader_id);
}
