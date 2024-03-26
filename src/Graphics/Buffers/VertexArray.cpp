#include <GL/glew.h>
#include<GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics::Buffers;

VertexArray::VertexArray() {
	glGenVertexArrays(1, &(this->id));
	glBindVertexArray(this->id);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &(this->id));
}