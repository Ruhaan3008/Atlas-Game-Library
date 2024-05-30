#pragma once
#include "STBI/stb_image.h"

#include <iostream>

namespace Atlas {
	namespace Graphics {
		class Texture {
		private:
			unsigned int m_ID;

		public:
			int height;
			int width;

			int colorChannels;

			int textureSlot;

			void SetTexture(const char* path);

			void Bind();
			void Unbind();

			Texture();
			~Texture();
		};
	}
}