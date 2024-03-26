#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics;

Mesh::Mesh() {
}

Mesh::Mesh(void* Vertices, unsigned int VertexCount, void* Indices, unsigned int IndexCount) {
	this->vertices = Vertices;
	this->vertexCount = VertexCount;

	this->indices = Indices;
	this->indexCount = IndexCount;
	
	this->vertexSize = sizeof(float) * this->vertexCount;
	this->indexSize = sizeof(float) * this->indexCount;
}