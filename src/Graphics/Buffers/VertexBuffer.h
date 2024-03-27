#pragma once

namespace Atlas {
	namespace Graphics {
		namespace Buffers {

			class VertexBuffer {
			private:
				unsigned int m_ID;

				unsigned int m_Size;

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