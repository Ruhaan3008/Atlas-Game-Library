#pragma once

#include "Buffers/Buffers.h"
#include "Shaders/Shader.h"

using namespace Atlas::Graphics::Buffers;

namespace Atlas {
	namespace Graphics {
		class Renderer {
		private:
			VertexBuffer m_VertexBuffer;
			IndexBuffer m_IndexBuffer;

			void Bind();
			void Unbind();
		public:
			Mesh mesh;
			Shader shader;

			//Set the Mesh
			void SetMesh(Mesh t_Mesh);

			//Set the shader
			void SetShader(Shader shader);

			//Renders the object to the screen
			void Draw();

			//Constructor
			Renderer();

			//Makes a Render object.
			Renderer(Mesh t_Mesh, Shader t_Shader);

			//Destroys Render object.
			~Renderer();

		};
	}
}