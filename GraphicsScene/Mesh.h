#pragma once
#include <glm/glm.hpp>
class Mesh
{
public:
	Mesh() : m_triCount(0), m_vao(0), m_vbo(0), m_ibo(0) {}
	virtual ~Mesh();

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec4 color;
		glm::vec2 texCoord;
	};

	void initializeQuad();

	virtual void draw();

protected:
	unsigned int m_triCount;
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;
};