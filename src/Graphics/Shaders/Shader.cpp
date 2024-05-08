#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics;

#ifdef ENABLE_ERROR_LOG

using namespace Atlas::CORE::Errors;

#endif

unsigned int Shader::CreateComponentShader(GLenum type,string ShaderSource) {
	//compiles component shader
	unsigned int shader = glCreateShader(type);
	const char* src = ShaderSource.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	//handle errors in the source code

#ifdef ENABLE_ERROR_LOG
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	//check if ther are any errors
	if (result == GL_FALSE) {
		//Creating the error message
		int lenght;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)malloc(lenght * sizeof(char));
		glGetShaderInfoLog(shader, lenght, &lenght, message);

		/*std::cout << "[Shader Compilation Error]: ";
		std::cout << message << '\n';
		std::cout << ShaderSource << '\n';
		std::cout << '\n';
		std::cout << '\n';*/

		string FinalMessage = "";
		FinalMessage += message;
		FinalMessage += '\n' + ShaderSource;

		Error ShaderError(ShaderCompilation, Moderate, FinalMessage, ErrorOrigin);
		ShaderError.LogErrorToFile();

		free(message);
#endif
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
	this->m_ShaderID = glCreateProgram();
	//unsigned int vertexShader = Shader::CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	//unsigned int fragmentShader = Shader::CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	//attaches component shader to master shaders
	glAttachShader(this->m_ShaderID, this->m_VertexShaderID);
	glAttachShader(this->m_ShaderID, this->m_FragmentShaderID);

	//compile the master shader
	glLinkProgram(this->m_ShaderID);

}

int Shader::GetUniform(char uniformName) {
	return glGetUniformLocation(this->m_ShaderID, &uniformName);
}

Shader::Shader(string VertexShaderPath, string FragmentShaderPath) {
	this->vertexShaderPath = VertexShaderPath;
	this->fragmentShaderPath = FragmentShaderPath;

	this->vertexShaderSource = ReadShaderFile(this->vertexShaderPath);
	this->fragmentShaderSource = ReadShaderFile(this->fragmentShaderPath);

	this->m_VertexShaderID = CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	this->m_FragmentShaderID = CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	CreateShader();

}

Shader::Shader() {
	string VertexShaderPath = 
		"#version 450 core \n"
		"precision highp float; \n"

		"out vec4 color; \n"
		"uniform vec4 InputColor; \n"

		"void main() { \n"
		"	color = InputColor; \n"
		"};" ;
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

	this->m_VertexShaderID = CreateComponentShader(GL_VERTEX_SHADER, this->vertexShaderSource);
	this->m_FragmentShaderID = CreateComponentShader(GL_FRAGMENT_SHADER, this->fragmentShaderSource);

	CreateShader();

}

Shader::~Shader() {
	glDeleteShader(this->m_VertexShaderID);
	glDeleteShader(this->m_FragmentShaderID);
	glDeleteShader(this->m_ShaderID);
}
