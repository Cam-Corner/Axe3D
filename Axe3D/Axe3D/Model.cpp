#include "Model.h"
#include "stb_image.h"
#include <glad/glad.h>


namespace axe
{
	std::vector<sTexture> Textures_Loaded;

	Model::Model()
	{

	}

	Model::Model(std::string* Path)
	{
		LoadModel(*Path);
	}

	Model::~Model()
	{

	}

	void Model::Load(std::string* Path)
	{
		LoadModel(*Path);
	}

	void Model::LoadModel(std::string Path)
	{
		Assimp::Importer Imp;
		const aiScene* Scene = Imp.ReadFile(Path, aiProcess_Triangulate | aiProcess_FlipUVs);

		if (!Scene || Scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !Scene->mRootNode)
		{
			std::cout << "MODEL::ERROR::ASSIMP: " << Imp.GetErrorString() << "\n";
		}
		_Directory = Path.substr(0, Path.find_last_of('/'));

		ProcessNode(Scene->mRootNode, Scene);
	}

	void Model::ProcessNode(aiNode* Node, const aiScene* Scene)
	{
		//process all the node's meshes
		for (unsigned int i = 0; i < Node->mNumMeshes; i++)
		{
			aiMesh* Mesh = Scene->mMeshes[Node->mMeshes[i]];
			_Meshes.push_back(ProcessMesh(Mesh, Scene));
		}

		for (unsigned int i = 0; i < Node->mNumChildren; i++)
		{
			ProcessNode(Node->mChildren[i], Scene);
		}
	}

	Mesh Model::ProcessMesh(aiMesh* Mesh, const aiScene* Scene)
	{
		std::vector<sVertex> Vertices;
		std::vector<unsigned int> Indices;
		std::vector<sTexture> Textures;

		for (unsigned int i = 0; i < Mesh->mNumVertices; i++)
		{
			sVertex Vertex;

			Vertex.Position.x = Mesh->mVertices[i].x;
			Vertex.Position.y = Mesh->mVertices[i].y;
			Vertex.Position.z = Mesh->mVertices[i].z;

			Vertex.Normal.x = Mesh->mNormals[i].x;
			Vertex.Normal.y = Mesh->mNormals[i].y;
			Vertex.Normal.z = Mesh->mNormals[i].z;

			if (Mesh->mTextureCoords[0] > 0)
			{
				Vertex.TextureCoords.x = Mesh->mTextureCoords[0][i].x;
				Vertex.TextureCoords.y = Mesh->mTextureCoords[0][i].y;
			}
			else
			{
				Vertex.TextureCoords = glm::vec2(0, 0);
			}

			Vertices.push_back(Vertex);
		}

		for (unsigned int i = 0; i < Mesh->mNumFaces; i++)
		{
			aiFace Face = Mesh->mFaces[i];

			for (unsigned int f = 0; f < Face.mNumIndices; f++)
			{
				Indices.push_back(Face.mIndices[f]);
			}
		}

		if (Mesh->mMaterialIndex >= 0)
		{
			aiMaterial* Material = Scene->mMaterials[Mesh->mMaterialIndex];
			
			std::vector<sTexture> DiffuseMaps = LoadMaterialTextures(Material, aiTextureType_DIFFUSE, "Texture_Diffuse");
			Textures.insert(Textures.end(), DiffuseMaps.begin(), DiffuseMaps.end());

			std::vector<sTexture> SpecularMaps = LoadMaterialTextures(Material, aiTextureType_SPECULAR, "Texture_Specular");
			Textures.insert(Textures.end(), SpecularMaps.begin(), SpecularMaps.end());
		}
		else
		{

		}

		return axe::Mesh(Vertices, Indices, Textures);
	}

	std::vector<sTexture> Model::LoadMaterialTextures(aiMaterial* Material, aiTextureType Type, std::string TypeName)
	{
		std::vector<sTexture> Textures;

		for (unsigned int i = 0; i < Material->GetTextureCount(Type); i++)
		{
			aiString string;
			Material->GetTexture(Type, i, &string);
			bool Skip = false;
			
			for (auto Texture : Textures_Loaded)
			{
				if (std::strcmp(Texture.Path.data(), string.C_Str()) == 0)
				{
					Textures.push_back(Texture);
					Skip = true;
					break;
				}
			}
			if (!Skip)
			{
				sTexture Texture;
				Texture.ID = TextureFromFile(string.C_Str(), _Directory);
				Texture.Type = TypeName;
				Texture.Path = string.C_Str();
				Textures.push_back(Texture);
				Textures_Loaded.push_back(Texture);
			}
		}
		
		return Textures;
	}

	void Model::Draw(axe::Shader Shader)
	{
		if (_Meshes.size() > 0)
		{
			for (auto M : _Meshes)
			{

				M.Draw(Shader);
			}
		}
	}

	unsigned int Model::TextureFromFile(const char* Path, const std::string& Directory, bool Gamma)
	{
		std::string FileName = std::string(Path);
		FileName = Directory + '/' + Path;

		unsigned int TextureID;
		glGenTextures(1, &TextureID);

		int Width, Height, NRChannels;
		unsigned char* Data = stbi_load(FileName.c_str(), &Width, &Height, &NRChannels, 0);
		if (Data)
		{
			GLenum Format;
			if (NRChannels == 1)
				Format = GL_RED;
			else if (NRChannels == 3)
				Format = GL_RGB;
			else if (NRChannels == 4)
				Format = GL_RGBA;


			glBindTexture(GL_TEXTURE_2D, TextureID);
			glTexImage2D(GL_TEXTURE_2D, 0, Format, Width, Height, 0, Format, GL_UNSIGNED_BYTE, Data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		else
		{
			std::cout << "MODEL::ERROR: Failed to load image!\n";
		}
		stbi_image_free(Data);

		return TextureID;
	}
}