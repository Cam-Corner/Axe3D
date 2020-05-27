#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Shader.h"
#include <unordered_map>

namespace Axe
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

	struct sMaterial
	{
		bool HasDiffuseTexture = false;
		bool HasSpecularTexture = false;
		glm::vec3 Diffuse{ 0, 0, 0 };
		glm::vec3 Specular{ 0, 0, 0 };
		glm::vec3 Ambient{ 0, 0, 0 };
		float Shininess;
	};

	class Mesh
	{
	public:
		Mesh(std::vector<sVertex> Vertices, std::vector<unsigned int> Indices, std::vector<sTexture> Textures);
		~Mesh();

		std::vector<sVertex> _Vertices;
		std::vector<unsigned int> _Indices;
		std::vector<sTexture> _Textures;

		sMaterial _Material;

		void Draw(Axe::Shader Shader);

	protected:



	private:

		unsigned int _VAO, _VBO, _EBO;

		void SetupMesh();
	};
}

