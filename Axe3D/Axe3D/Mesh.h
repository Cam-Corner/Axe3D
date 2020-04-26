#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Shader.h"

namespace axe
{
	struct sVertex
	{
		glm::vec3 Position{ 0, 0, 0 };
		glm::vec3 Normal{ 0, 0, 0 };
		glm::vec2 TextureCoords{ 0, 0 };
	};

	struct sTexture
	{
		unsigned int ID;
		std::string Type;
		std::string Path;
	};

	class Mesh
	{
	public:
		Mesh(std::vector<sVertex> Vertices, std::vector<unsigned int> Indices, std::vector<sTexture> Textures);
		~Mesh();

		std::vector<sVertex> _Vertices;
		std::vector<unsigned int> _Indices;
		std::vector<sTexture> _Textures;

		void Draw(axe::Shader Shader);

	protected:



	private:

		unsigned int _VAO, _VBO, _EBO;

		void SetupMesh();
	};
}

