#pragma once
#include <iostream>

#include "../Graphics.h"

namespace Atlas {
	namespace Graphics {
		class Shader {
		private:
			unsigned int m_ShaderID;

			unsigned int m_VertexShaderID;
			unsigned int m_FragmentShaderID;

		public:

			std::string vertexShaderPath;
			std::string fragmentShaderPath;

			std::string vertexShaderSource;
			std::string fragmentShaderSource;


			//Create and compile the master shader. NOTE: Works only if the component shader have been compiled.
			void CreateShader();

			//Compiles component shader with the source code. NOTE: Shader source code is the parameter, not file path
			unsigned int CreateComponentShader(GLenum type,std::string ShaderSource);

			//Reads the source code from the glsl file.
			std::string ReadShaderFile(std::string path);

			//Gets the location of the uniform. To write to the uniform use glUniform
			int GetUniform(const char* uniformName);

			//Returns the shader ID
			unsigned int GetShaderID() const { return m_ShaderID; };

			//Uses shader for rendering.
			void Use() {
				glUseProgram(m_ShaderID);
			};

			//Makes a default white shader.
			Shader();
			//Makes the shader with the file path.
			Shader(std::string VertexShaderPath, std::string FragmentShaderPath);

			//Free memory and shaders
			~Shader();

		};
	}
}