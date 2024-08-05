#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Textures/Texture.h"
#include "../../Math.h"

using namespace glm;

namespace Atlas {
	namespace Graphics {
		class Shader {
		private:
			unsigned int m_ShaderID;

			unsigned int m_VertexShaderID;
			unsigned int m_FragmentShaderID;

			std::string m_VertexShaderSource;
			std::string m_FragmentShaderSource;

			std::string ReadShaderFile(std::string path);

			void CombineComponentShaders();
			unsigned int CompileComponentShader(GLenum type,std::string ShaderSource);
		public:

			std::string vertexShaderPath;
			std::string fragmentShaderPath;

			unsigned int GetShaderID() const { return m_ShaderID; };

			//Uses shader for rendering.
			void Use() const { glUseProgram(m_ShaderID); };

			Shader();
			Shader(const std::string VertexShaderPath, const std::string FragmentShaderPath);

			~Shader();

		public:
			int GetUniform(const char* uniformName) const;

			void SetUniform(std::string uniformName, int data) const;
			void SetUniform(std::string uniformName, Texture texture) const;
			void SetUniform(std::string uniformName, mat4x4 Matrix) const;
		};
	}
}