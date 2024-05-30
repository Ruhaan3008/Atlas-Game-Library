#include "Texture.h"
#include "STBI/stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace Atlas::Graphics;

void Texture::SetTexture(const char* path){
	unsigned char* data = stbi_load(path, &width, &height, &colorChannels, 0);

	this->Bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	glGenerateMipmap(GL_TEXTURE_2D);

}

void Texture::Bind(){
	//glActiveTexture(33984 + textureSlot);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::Unbind(){
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture(){
	height = 500;
	width = 500;

	colorChannels = 0;

	textureSlot = 0;

	glGenTextures(1, &m_ID);
	this->Bind();

	//texture parameters:
	//texture wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//mipmap settings
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

Texture::~Texture(){
	glDeleteTextures(1, &m_ID);
}
