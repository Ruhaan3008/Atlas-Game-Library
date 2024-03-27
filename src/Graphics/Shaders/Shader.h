#pragma once
#include <iostream>

#include "../Graphics.h"

typedef std::string string;

namespace Atlas {
	namespace Graphics {
		class Shader {
		private:
			unsigned int m_ShaderID;

			unsigned int m_VertexShaderID;
			unsigned int m_FragmentShaderID;

		public:

			string vertexShaderPath;
			string fragmentShaderPath;

			string vertexShaderSource;
			string fragmentShaderSource;


			//Create and compile the master shader. NOTE: Works only if the component shader have been compiled.
			void CreateShader();

			//Compiles component shader with the source code. NOTE: Shader source code is the parameter, not file path
			unsigned int CreateComponentShader(GLenum type,string ShaderSource);

			//Reads the source code from the glsl file.
			string ReadShaderFile(string path);

			//Gets the location of the uniform. To write to the uniform use glUniform
			int GetUniform(char uniformName);

			//Returns the shader ID
			unsigned int GetShaderID() const { return m_ShaderID; };

			//Makes a default white shader.
			Shader();
			//Makes the shader with the file path.
			Shader(string VertexShaderPath, string FragmentShaderPath);

			//Free memory and shaders
			~Shader();

		};
	}
}