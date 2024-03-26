#pragma once

namespace Atlas {
	namespace Graphics {
		namespace Buffers {


			struct VertexBufferLayout {
			public:
				GLenum type;
				unsigned int count;
				void* pointer;
				bool normalised;
				unsigned int stride;

				bool IsEmpty;

				VertexBufferLayout();
				VertexBufferLayout(GLenum Type, unsigned int Count,
					void* Pointer, bool Normalized, unsigned int Stride);

			};

			class VertexBuffer {
			private:
				unsigned int id;

				unsigned int size;

				VertexBufferLayout positionAttributes;
				VertexBufferLayout textureAttributes;

				void SetAttributes(VertexBufferLayout layout);


			public:

				void Bind();
				void Unbind();

				void SetData(const void* data, unsigned int size);
				
				VertexBuffer();
				/*Create a new VertexBuffer object.
				Create a new buffer and assigns the data to the buffer.
				The buffer still needs to be binded to render anything.*/
				VertexBuffer(const void* data, unsigned int size);
				~VertexBuffer();
			};
		}
	}
}