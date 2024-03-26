#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics::Buffers;

VertexBuffer::VertexBuffer() {
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);

}

VertexBuffer::VertexBuffer(const void* data, unsigned int Size) {
    this->size = Size;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW);

}
void VertexBuffer::SetData(const void* data, unsigned int Size) {
    this->size = Size;
    glBufferData(GL_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW);

}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);

}

void VertexBuffer::SetAttributes(VertexBufferLayout layout) {
    if (!layout.IsEmpty) {

        GLenum normalized = layout.normalised ? GL_TRUE : GL_FALSE;

        glVertexAttribPointer(0, layout.count,layout.type, normalized, layout.stride, layout.pointer);
        glEnableVertexAttribArray(0);
    }

}

void VertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);

}

void VertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

VertexBufferLayout::VertexBufferLayout() {
    this->IsEmpty = true;
    this->count = NULL;
    this->normalised = NULL;
    this->pointer = NULL;
    this->stride = NULL;
    this->type = NULL;

}

VertexBufferLayout::VertexBufferLayout(GLenum Type, unsigned int Count,
    void* Pointer, bool Normalized, unsigned int Stride)
    : type(Type), count(Count), pointer(Pointer), normalised(Normalized),
    stride(Stride), IsEmpty(false) {};