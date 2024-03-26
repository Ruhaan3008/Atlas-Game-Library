#pragma once

#include "../../Atlas.h"

namespace Atlas {
	namespace Graphics {
		namespace Buffers {

			class IndexBuffer {
			private:
				unsigned int id;
				unsigned int size;

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