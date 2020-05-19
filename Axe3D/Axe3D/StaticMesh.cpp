#include "StaticMesh.h"
#include <glm/gtc/matrix_transform.hpp>
#include "ModelManager.h"
#include "RenderWindow.h"

namespace Axe
{
	StaticMesh::StaticMesh()
	{
		Axe::ModelManager::AddStaticMesh(this);
	}

	StaticMesh::~StaticMesh()
	{
		Axe::ModelManager::RemoveStaticMesh(this);
	}

	bool StaticMesh::SetModel(Axe::Model* Model)
	{
		if (Model != NULL)
		{
			_Model = Model;
			return true;
		}

		std::cout << "ERROR::STATIC::MESH: Model is NULL \n";

		return false;
	}

	bool StaticMesh::SetModel(std::string* ModelName)
	{
		_Model = Axe::ModelManager::GetModel(*ModelName);

		if (_Model == NULL)
		{
			std::cout << "ERROR::STATIC::MESH: " << ModelName << " not found! \n";
			return false;
		}

		return true;
	}

	glm::mat4 StaticMesh::GetModelMatrix()
	{
		glm::mat4 Model = glm::mat4(1.0f);
		Model = glm::translate(Model, _Position);
	    Model = glm::rotate(Model, 0.0f, _Rotation);
		Model = glm::scale(Model, _Scale);

		return Model;
	}

	void StaticMesh::SetShader(Axe::Shader* Shader)
	{
		if (Shader != NULL)
		{
			_Shader = Shader;
		}
	}

	bool StaticMesh::Draw()
	{
		if (_Shader != NULL)
		{
			_Shader->UseProgram();
			
			glm::mat4 Projection = Axe::RenderWindow::GetActiveCamera()->GetProjectionMatrix();
			_Shader->SetMat4("Projection", Projection);

			glm::mat4 View = Axe::RenderWindow::GetActiveCamera()->GetViewMatrix();
			_Shader->SetMat4("View", View);

			glm::mat4 Model = GetModelMatrix();
			_Shader->SetMat4("Model", Model);

			_Model->Draw(*_Shader);

			return true;
		}

		std::cout << "ERROR::STATIC::MESH: Static Mesh has no shader! \n";

		return false;
	}
}