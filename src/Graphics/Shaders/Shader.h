#pragma once
#include <iostream>

#include "../Graphics.h"

typedef std::string string;

namespace Atlas {
	namespace Graphics {
		class Shader {
		private:
			unsigned int shader_id;

		public:

			string vertexShaderPath;
			string fragmentShaderPath;

			string vertexShaderSource;
			string fragmentShaderSource;

			unsigned int vertexShader;
			unsigned int fragmentShader;


			//Create and compile the master shader. NOTE: Works only if the component shader have been crated.
			void CreateShader();

			//Compiles component shader. NOTE: Shader source code is the parameter, not file path
			unsigned int CreateComponentShader(GLenum type,string ShaderSource);
			//Reads the source code from the glsl file.
			string ReadShaderFile(string path);

			//Gets the location of the uniform. To write to the uniform use glUniform
			int GetUniform(char uniformName);

			unsigned int GetShaderID() const { return shader_id; };

			Shader();
			//Constructor
			Shader(string VertexShaderPath, string FragmentShaderPath);
			//Destructor
			~Shader();

		};
	}
}