#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../Atlas.h"

using namespace Atlas::Graphics;

Mesh::Mesh() {

	this->vertices = NULL;
	this->vertexCount = 0;

	this->indices = NULL;
	this->indexCount = 0;

	this->vertexSize = sizeof(float) * this->vertexCount * 8;
	this->indexSize = sizeof(unsigned int) * this->indexCount;
}

Mesh::Mesh(void* Vertices, unsigned int VertexCount, void* Indices, unsigned int IndexCount) {
	this->vertices = Vertices;
	this->vertexCount = VertexCount;

	this->indices = Indices;
	this->indexCount = IndexCount;
	
	this->vertexSize = sizeof(float) * this->vertexCount * 8;
	this->indexSize = sizeof(unsigned int) * this->indexCount;
}