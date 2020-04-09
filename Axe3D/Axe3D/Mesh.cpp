#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Mesh::Mesh()
{
	glGenBuffers(1, &m_VBO);
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_EBO);
}

Mesh::~Mesh()
{

}

bool Mesh::LoadModel(std::string fLocation)
{


	return true;
}

bool Mesh::SetupVertices(const float fVerticePositions[], const float fVerticeTextCoords, const unsigned int fArraySize)
{
	for (int i = 0; i < fArraySize; i++)
	{
		sVertices Temp;
		Temp.Position.x = fVerticePositions[i];
		Temp.Position.y = fVerticePositions[i + 1];
		Temp.Position.z = fVerticePositions[i + 2];

		m_Vertices.push_back(Temp);
	}

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(sVertices), &m_Vertices[0].Position, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	m_UsingEBO = false;
	return true;
}


bool Mesh::SetupIndices(const unsigned int fIndices[], const unsigned int fArraySize)
{
	for (int i = 0; i < fArraySize; i++)
	{
		m_Indices.push_back(fIndices[i]);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int) , &m_Indices[0], GL_STATIC_DRAW);

	m_UsingEBO = true;
	return true;
}

void Mesh::Draw()
{
	if (m_UsingEBO)
	{
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glDrawElements(GL_TRIANGLES, 32, GL_UNSIGNED_INT, 0);

	}
	else
	{
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 32);
	}
}