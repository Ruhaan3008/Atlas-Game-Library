#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics::Buffers;

IndexBuffer::IndexBuffer() {

    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

IndexBuffer::IndexBuffer(const void* data, unsigned int size) {
    this->m_Size = size;
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_ID);

}

void IndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);

}

void IndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}