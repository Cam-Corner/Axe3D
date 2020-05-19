#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Model.h"


namespace Axe
{
	class StaticMesh
	{
	public:
		StaticMesh();
		~StaticMesh();

		friend class ModelManager;
	protected:
		glm::mat4 GetModelMatrix();

	public:
		glm::vec3& GetPosition() { return _Position; }
		glm::vec3& GetRotation() { return _Rotation; }
		glm::vec3& GetScale() { return _Scale; }

		bool SetModel(Axe::Model* Model);
		bool SetModel(std::string* ModelName);
		void SetShader(Axe::Shader* Shader);

		Axe::Model* GetModel() { return _Model; }

	private:
		bool Draw();

		glm::vec3 _Position{ 0, 0, 0 };
		glm::vec3 _Rotation{ 1, 1, 1 };
		glm::vec3 _Scale{ 1, 1, 1 };

		Axe::Model* _Model;
		Axe::Shader* _Shader;
	};
}

