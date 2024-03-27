#include "../Atlas.h"

using namespace Atlas::Graphics;
using namespace Atlas::Graphics::Buffers;


RenderObject::RenderObject(){

}

RenderObject::RenderObject(Mesh t_Mesh, Shader t_Shader) {
	mesh = t_Mesh;
	shader = t_Shader;

	ErrCall(m_VertexBuffer.SetData(mesh.vertices, mesh.vertexSize));
	ErrCall(m_IndexBuffer = IndexBuffer(mesh.indices, mesh.indexSize));

	ErrCall(m_VertexBuffer.Bind());

	glUseProgram(shader.GetShaderID());
}

void RenderObject::SetMesh(Mesh t_Mesh) {

	mesh = t_Mesh;

	m_VertexBuffer.SetData(mesh.vertices, mesh.vertexSize);
	m_IndexBuffer = IndexBuffer(mesh.indices, mesh.indexSize);

	m_VertexBuffer.Bind();
	m_IndexBuffer.Bind();
}

void RenderObject::SetShader(Shader t_Shader) {
	shader = t_Shader;

	glUseProgram(shader.GetShaderID());

}

RenderObject::~RenderObject() {
	m_VertexBuffer.~VertexBuffer();
	m_IndexBuffer.~IndexBuffer();

	shader.~Shader();
}