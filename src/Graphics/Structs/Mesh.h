#pragma once

namespace Atlas {
	namespace Graphics {
		struct Mesh {
		private:
		public:
			void* vertices;
			unsigned int vertexCount;

			void* indices;
			unsigned int indexCount;

			unsigned int vertexSize;
			unsigned int indexSize;

			Mesh();
			Mesh(void* Vertices,unsigned int VertexCount, void* indexCount, unsigned int IndexCount) ;
		};
	}
}