#include "Shader.h"

using namespace Atlas::Graphics;

void Shader::SetUniform(std::string uniformName, int data) const{
	int location = this->GetUniform(uniformName.c_str());
	glUniform1i(location, data); 
}

void Shader::SetUniform(std::string uniformName, Texture texture) const{
	SetUniform(uniformName, texture.slot);
}

void Shader::SetUniform(std::string uniformName, mat4x4 Matrix) const{
	int location = this->GetUniform(uniformName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(Matrix));
}