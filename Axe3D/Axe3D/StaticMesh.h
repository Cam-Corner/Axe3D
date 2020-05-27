#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Model.h"
#include "Component.h"

namespace Axe
{
	class StaticMesh : public Component
	{
	public:
		StaticMesh();
		~StaticMesh();

		friend class ModelManager;
	public:

		bool SetModel(Axe::Model* Model);
		bool SetModel(std::string* ModelName);

		Axe::Model* GetModel() { return _Model; }
	
		bool Draw(Axe::Shader& Shader);

	private:
		Axe::Model* _Model;
	};
}

