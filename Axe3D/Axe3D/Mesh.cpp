#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "RenderWindow.h"

namespace axe
{
	Mesh::Mesh(std::vector<sVertex> Vertices, std::vector<unsigned int> Indices, std::vector<sTexture> Textures)
	{
		_Vertices = Vertices;
		_Indices = Indices;
		_Textures = Textures;

		SetupMesh();
	}

	Mesh::~Mesh()
	{

	}

	void Mesh::SetupMesh()
	{

		//generate IDs
		glGenVertexArrays(1, &_VAO);
		glGenBuffers(1, &_VBO);
		glGenBuffers(1, &_EBO);

		//bind the VAO
		glBindVertexArray(_VAO);
		
		//bind vbo and add data
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glBufferData(GL_ARRAY_BUFFER, _Vertices.size() * sizeof(sVertex), &_Vertices[0] , GL_STATIC_DRAW);

		//bind ebo and add data
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _Indices.size() * sizeof(unsigned int), &_Indices[0], GL_STATIC_DRAW);

		//binding attributes and setting offsets
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, Normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, TextureCoords));

		glBindVertexArray(0);
	}

	void Mesh::Draw(axe::Shader Shader)
	{
		unsigned int DiffuseNum = 1;
		unsigned int SpecularNum = 1;

		for (unsigned int i = 0; i < _Textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			
			std::string TextureNum;
			std::string TextureName = _Textures[i].Type;
			
			if (TextureName == "Texture_Diffuse")
			{
				TextureNum = DiffuseNum;
				DiffuseNum++;
			}
			else if (TextureName == "Texture_Specular")
			{
				TextureNum = SpecularNum;
				SpecularNum++;
			}

			Shader.SetFloat("Material." + TextureName + TextureNum, i);
			glBindTexture(GL_TEXTURE_2D, _Textures[i].ID);
		}

		glBindVertexArray(_VAO);
		glDrawElements(GL_TRIANGLES, _Indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glActiveTexture(GL_TEXTURE0);
	}
}