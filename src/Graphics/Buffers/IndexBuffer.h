#pragma once

#include "../../Atlas.h"

namespace Atlas {
	namespace Graphics {
		namespace Buffers {

			class IndexBuffer {
			private:
				unsigned int m_ID;
				unsigned int m_Size;

			public:
				void Bind();
				void Unbind();


				IndexBuffer();
				IndexBuffer(const void* data, unsigned int size);
				~IndexBuffer();
			};

		}
	}
}