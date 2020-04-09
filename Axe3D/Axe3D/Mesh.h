#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>

class Mesh
{
private:
	struct sVertices
	{
		glm::vec3 Position{ 0, 0, 0 };
		glm::vec2 TextCoords{ 0, 0 };
	};


public:
	Mesh();
	~Mesh();

	bool LoadModel(std::string fLocation);
	bool SetupVertices(const float fVerticePositions[], const float fVerticeTextCoords, const unsigned int fArraySize);
	bool SetupIndices(const unsigned int fIndices[], const unsigned int fArraySize);
	void Draw();

protected:
	unsigned int m_VBO, m_VAO, m_EBO;
	std::vector<sVertices> m_Vertices;
	std::vector<unsigned int> m_Indices;

private:
	bool m_UsingEBO{ false };

	
};

