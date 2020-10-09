#include "Mesh.h"
#include <gl_core_4_4.h>

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::initializeQuad()
{
	// check if the mesh isn't initialized
	assert(m_vao == 0);
	// generate buffers
	glGenBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);

	//bind vertex array or the mesh wrapper
	glBindVertexArray(m_vao);
	
	// bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	Vertex vertices[6];
	vertices[0].position = { -0.5f,0, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0, -0.5f, 1 };

	vertices[3].position = { -0.5f, 0, -0.5f, 1 };
	vertices[4].position = { 0.5f, 0, 0.5f, 1 };
	vertices[5].position = { 0.5f, 0, -0.5f, 1 };

	//fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	//unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//quad has 2 triangles
	m_triCount = 2;

}

void Mesh::draw()
{
	glBindVertexArray(m_vao);
	//Checks to see if indices or vertices are being used
	if (m_ibo != 0)
	{
		glDrawElements(GL_TRIANGLES, 3 * m_triCount, GL_UNSIGNED_INT, 0);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, 3 * m_triCount);
	}
}
