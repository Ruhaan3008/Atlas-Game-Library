#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics;

#ifdef ENABLE_ERROR_LOG

using namespace Atlas::CORE::Errors;

#endif

unsigned int Shader::CompileComponentShader(GLenum type, std::string ShaderSource) {
	//compiles component shader
	unsigned int shader = glCreateShader(type);
	const char* src = ShaderSource.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	//handle errors in the source code

	#ifdef ENABLE_ERROR_LOG
	{
		int result;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

		//check if ther are any errors
		if (result == GL_FALSE) {
			//Creating the error message
			int lenght;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
			char* message = (char*)malloc(lenght * sizeof(char));
			glGetShaderInfoLog(shader, lenght, &lenght, message);

			std::string FinalMessage = "";
			if (message != 0) {
				FinalMessage += (std::string)message;
			}
			FinalMessage += '\n' + ShaderSource;

			Error ShaderError(ErrorType::ShaderCompilation, ErrorSeverity::Moderate, FinalMessage, ErrorOrigin);
			ShaderError.LogErrorToFile();

			free(message);
		}
	}
	#endif

	return shader;

}

std::string Shader::ReadShaderFile(std::string path) {

	std::ifstream file(path);

	if (!file.is_open()) {
		return "";
	}

	std::stringstream ss{};
	ss << file.rdbuf();
	file.close();

	return ss.str();
}

void Shader::CombineComponentShaders() {
	//vertex and fragment shader
	this->m_ShaderID = glCreateProgram();

	//attaches component shader to master shaders
	glAttachShader(this->m_ShaderID, this->m_VertexShaderID);
	glAttachShader(this->m_ShaderID, this->m_FragmentShaderID);

	//compile the master shader
	glLinkProgram(this->m_ShaderID);

}

int Shader::GetUniform(const char* uniformName) {
	return glGetUniformLocation(this->m_ShaderID, uniformName);
}

Shader::Shader(const std::string VertexShaderPath, const std::string FragmentShaderPath) {
	this->m_ShaderID = glCreateProgram();

	this->vertexShaderPath = VertexShaderPath;
	this->fragmentShaderPath = FragmentShaderPath;

	this->m_VertexShaderSource = ReadShaderFile(this->vertexShaderPath);
	this->m_FragmentShaderSource = ReadShaderFile(this->fragmentShaderPath);

	this->m_VertexShaderID = CompileComponentShader(GL_VERTEX_SHADER, this->m_VertexShaderSource);
	this->m_FragmentShaderID = CompileComponentShader(GL_FRAGMENT_SHADER, this->m_FragmentShaderSource);

	CombineComponentShaders();

}

Shader::Shader() {
	this->m_ShaderID = glCreateProgram();

	std::string VertexShaderSource = "";
	std::string FragmentShaderSource = "";
	this->vertexShaderPath = "";
	this->fragmentShaderPath = "";

	this->m_VertexShaderSource = VertexShaderSource;
	this->m_FragmentShaderSource = FragmentShaderSource;

	this->m_VertexShaderID = CompileComponentShader(GL_VERTEX_SHADER, this->m_VertexShaderSource);
	this->m_FragmentShaderID = CompileComponentShader(GL_FRAGMENT_SHADER, this->m_FragmentShaderSource);

	CombineComponentShaders();

}

Shader::~Shader() {
	glDeleteShader(this->m_VertexShaderID);
	glDeleteShader(this->m_FragmentShaderID);
	glDeleteShader(this->m_ShaderID);
}
