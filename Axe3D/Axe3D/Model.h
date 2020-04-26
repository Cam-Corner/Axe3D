#pragma once
#include <iostream>
#include <vector>
#include "Shader.h"
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace axe
{
	class Model
	{
	public:
		Model();
		Model(std::string* Path);
		~Model();

		void Load(std::string* Path);
		void Draw(axe::Shader Shader);

	protected:


	private:
		std::vector<Mesh> _Meshes;
		std::string _Directory;

		void LoadModel(std::string Path);
		void ProcessNode(aiNode* Node, const aiScene* Scene);
		Mesh ProcessMesh(aiMesh* Mesh, const aiScene* Scene);
		std::vector<sTexture> LoadMaterialTextures(aiMaterial* Material, aiTextureType Type, std::string TypeName);

		unsigned int TextureFromFile(const char* Path, const std::string& Directory, bool Gamma = false);
	};
}

