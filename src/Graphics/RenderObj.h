#pragma once

#include "Buffers/Buffers.h"
#include "Shaders/Shader.h"

using namespace Atlas::Graphics::Buffers;

namespace Atlas {
	namespace Graphics {
		struct RenderObject {
		private:
			VertexBuffer m_VertexBuffer;
			IndexBuffer m_IndexBuffer;
		public:
			Mesh mesh;
			Shader shader;

			//Set the Mesh
			void SetMesh(Mesh t_Mesh);

			//Set the shader
			void SetShader(Shader shader);

			//Constructor
			RenderObject();

			//Makes a Render object.
			RenderObject(Mesh t_Mesh, Shader t_Shader);

			//Destroys Render object.
			~RenderObject();

		};
	}
}