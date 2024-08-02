#pragma once
#include <iostream>

#include "../Textures/Texture.h"

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


			int GetUniform(const char* uniformName);
			void SetUniformTexture(const char* textureName, Texture texture);

			unsigned int GetShaderID() const { return m_ShaderID; };

			//Uses shader for rendering.
			void Use() { glUseProgram(m_ShaderID); };

			Shader();
			Shader(const std::string VertexShaderPath, const std::string FragmentShaderPath);

			~Shader();
		};
	}
}