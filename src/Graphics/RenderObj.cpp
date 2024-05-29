#include "../Atlas.h"

using namespace Atlas::Graphics;
using namespace Atlas::Graphics::Buffers;


Renderer::Renderer(){

}

Renderer::Renderer(Mesh t_Mesh, Shader t_Shader) {
	mesh = t_Mesh;
	shader = t_Shader;

	m_VertexBuffer.SetData(mesh.vertices, mesh.vertexSize);
	m_IndexBuffer.SetData(mesh.indices, mesh.indexSize);

	m_VertexBuffer.Bind();

	shader.Use();
}

void Renderer::SetMesh(Mesh t_Mesh) {

	mesh = t_Mesh;

	m_VertexBuffer.SetData(mesh.vertices, mesh.vertexSize);
	m_IndexBuffer.SetData(mesh.indices, mesh.indexSize);

	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();
}

void Renderer::DrawCall() {
	this->Bind();

	shader.Use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Renderer::Bind() {
	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();

}

void Renderer::Unbind() {
	m_VertexBuffer.Unbind();
	m_IndexBuffer.Unbind();

}

void Renderer::SetShader(Shader t_Shader) {
	shader = t_Shader;

	glUseProgram(shader.GetShaderID());

}

Renderer::~Renderer() {
	m_VertexBuffer.~VertexBuffer();
	m_IndexBuffer.~IndexBuffer();

	shader.~Shader();
}