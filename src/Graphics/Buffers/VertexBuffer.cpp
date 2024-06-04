#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics::Buffers;

VertexBuffer::VertexBuffer() {
    m_Size = NULL;
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);

}

VertexBuffer::VertexBuffer(const void* data, unsigned int Size) {
    this->m_Size = Size;
    glGenBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW);

}
void VertexBuffer::SetData(const void* data, unsigned int Size) {
    this->m_Size = Size;
    glBufferData(GL_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW);

}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_ID);

}

void VertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 12);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 24);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


}

void VertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}